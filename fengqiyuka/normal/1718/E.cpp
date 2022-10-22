#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
const ll mod=1e9+7;
vector<int> a[N],w[N];

map<ll,int> G;
map<int,int> B1[N],B2[N];

bitset<N> b;

set<int> S1[N],S2[N],S3[N],S4[N],S5,S6;
set<int>::iterator iter,iter1,iter2;

int ID1[N],ID2[N],ID3[N],ID4[N],Ans1[N],Ans2[N],List[N],Ans[N][3];
int Cnt1[N],Cnt2[N],Cnt3[N],Cnt4[N],cnt1=0,cnt2=0;

bool vis1[N],vis2[N],bk[N];int sta[N],tot=0;ll Mi[N];


int main()
{

    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++) a[i].resize(m+1),w[i].resize(m+1);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]) B1[i][a[i][j]]=j,B2[j][a[i][j]]=i;
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&w[i][j]);
            
    Mi[0]=1;for(int i=1;i<=200000;i++) Mi[i]=(Mi[i-1]+Mi[i-1])%mod;

    for(int i=1;i<=n;i++){
    	ll Sum=0; 
        for(int j=1;j<=m;j++)
            if(a[i][j]) Sum=(Sum+Mi[a[i][j]])%mod;
        if(G[Sum]==0) G[Sum]=++cnt1;
        ID1[i]=G[Sum];Cnt1[ID1[i]]++;
    }

    for(int i=1;i<=n;i++){
    	ll Sum=0;
        for(int j=1;j<=m;j++)
            if(w[i][j]) Sum=(Sum+Mi[w[i][j]])%mod;
        if(G[Sum]==0){
            printf("-1\n");
            return 0;
        }
        ID3[i]=G[Sum];Cnt3[ID3[i]]++;
        if(Cnt3[ID3[i]]>Cnt1[ID3[i]]){
            printf("-1\n");
            return 0;
        }
    }

    G.clear();
    for(int i=1;i<=m;i++){
    	ll Sum=0;
        for(int j=1;j<=n;j++)
            if(a[j][i]) Sum=(Sum+Mi[a[j][i]])%mod;
        if(G[Sum]==0) G[Sum]=++cnt2;
        ID2[i]=G[Sum];Cnt2[ID2[i]]++;
    }

    for(int i=1;i<=m;i++){
        ll Sum=0;
        for(int j=1;j<=n;j++)
            if(w[j][i]) Sum=(Sum+Mi[w[j][i]])%mod;
        if(G[Sum]==0){
        	printf("-1\n");
        	return 0;
		}
        ID4[i]=G[Sum];Cnt4[ID4[i]]++;
        if(Cnt4[ID4[i]]>Cnt2[ID4[i]]){
            printf("-1\n");
            return 0;
        }
    }

    for(int i=1;i<=n;i++){
        S1[ID1[i]].insert(i);
        S3[ID3[i]].insert(i);
    }
    for(int i=1;i<=m;i++){
        S2[ID2[i]].insert(i);
        S4[ID4[i]].insert(i);
    }
    for(int i=1;i<=cnt1;i++) S5.insert(i);
    for(int i=1;i<=cnt2;i++) S6.insert(i);

    memset(vis1,true,sizeof(vis1));
    memset(vis2,true,sizeof(vis2));

    int st=0,ed=0;
    for(int i=1;i<=n;i++)
        if(Cnt1[ID3[i]]==1){
            List[++ed]=i;
            vis1[i]=false;
            iter1=S1[ID3[i]].begin(),iter2=S3[ID3[i]].begin();
            Ans1[*iter2]=(*iter1);
            S1[ID3[i]].clear();S3[ID3[i]].clear();
            S5.erase(ID3[i]);
            //remember to do something!
        }
    for(int i=1;i<=m;i++)
        if(Cnt2[ID4[i]]==1){
            List[++ed]=n+i;
            vis2[i]=false;
            iter1=S2[ID4[i]].begin();iter2=S4[ID4[i]].begin();
            Ans2[*iter2]=(*iter1);
            S2[ID4[i]].clear();S4[ID4[i]].clear();
            S6.erase(ID4[i]);
        }

    while(1){
        while(st<ed){
            int x=List[++st];
            if(x<=n){
                for(int j=1;j<=m;j++){
                    if(w[x][j]&&vis2[j]){
                        Ans2[j]=B1[Ans1[x]][w[x][j]];
                        S2[ID4[j]].erase(Ans2[j]);
                        S4[ID4[j]].erase(j);
                        List[++ed]=j+n;
                        vis2[j]=false;
                        if(S2[ID4[j]].size()==1){
                            iter1=S2[ID4[j]].begin();iter2=S4[ID4[j]].begin();
                            Ans2[*iter2]=(*iter1);vis2[*iter2]=false;
                            List[++ed]=(*iter2)+n;
                            S2[ID4[j]].clear();S4[ID4[j]].clear();
                            S6.erase(ID4[j]);
                        }
                    }
                    else if(w[x][j]&&Ans2[j]!=B1[Ans1[x]][w[x][j]]){
                    	printf("-1\n");
                    	return 0;
					}
                }
            }
            else{
                x-=n;
                for(int j=1;j<=n;j++){
                    if(w[j][x]&&vis1[j]){
                        Ans1[j]=B2[Ans2[x]][w[j][x]];
                        S1[ID3[j]].erase(Ans1[j]);
                        S3[ID3[j]].erase(j);
                        vis1[j]=false;
                        List[++ed]=j;
                        if(S1[ID3[j]].size()==1){
                            iter1=S1[ID3[j]].begin();iter2=S3[ID3[j]].begin();
                            Ans1[*iter2]=(*iter1);vis1[*iter2]=false;
                            List[++ed]=(*iter2);
                            S1[ID3[j]].clear();S3[ID3[j]].clear();
                            S5.erase(ID3[j]);
                        }
                    }
                    else if(w[j][x]&&Ans1[j]!=B2[Ans2[x]][w[j][x]]){
                    	printf("-1\n");
                    	return 0;
					}
                }
            }
        }

        if(ed<n+m){
            if(!S5.empty()){
                iter=S5.begin();
                int t=(*iter);
                iter1=S1[t].begin();iter2=S3[t].begin();
                Ans1[*iter2]=(*iter1);vis1[*iter2]=false;
                List[++ed]=(*iter2);
                S1[t].erase(iter1);S3[t].erase(iter2);
                // S1[t].clear();S3[t].clear();
                if(S1[t].empty()) S5.erase(iter);
            }
            else{
                iter=S6.begin();
                int t=(*iter);
                iter1=S2[t].begin();iter2=S4[t].begin();
                Ans2[*iter2]=(*iter1);vis2[*iter2]=false;
                List[++ed]=(*iter2)+n;
                S2[t].erase(iter1);S4[t].erase(iter2);
                if(S2[t].empty()) S6.erase(iter);
            }
        }
        else break;
    }

    memset(bk,true,sizeof(bk));
    for(int i=1;i<=n;i++)
        if(bk[i]){
            int t=i,cnt=0;
            while(bk[t]) sta[++cnt]=t,bk[t]=false,t=Ans1[t];
            for(int j=cnt-1;j>=1;j--)
                Ans[++tot][0]=1,Ans[tot][1]=sta[j],Ans[tot][2]=sta[j+1];
        }

    memset(bk,true,sizeof(bk));
    for(int i=1;i<=m;i++)
        if(bk[i]){
            int t=i,cnt=0;
            while(bk[t]) sta[++cnt]=t,bk[t]=false,t=Ans2[t];
            for(int j=cnt-1;j>=1;j--)
                Ans[++tot][0]=2,Ans[tot][1]=sta[j],Ans[tot][2]=sta[j+1];
        }

    printf("%d\n",tot);
    for(int i=tot;i>=1;i--) printf("%d %d %d\n",Ans[i][0],Ans[i][1],Ans[i][2]);

    return 0;
}