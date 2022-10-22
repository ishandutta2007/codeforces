#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int dis[N],ID[N],sta[N],sta2[N],g[N],fa[N],b[15][N],w1[N],w2[N],h[N];
char s1[N],s2[N];bool vis[N];
vector<int> B[N];

int n;
void query(){
    printf("? ");
    for(int i=1;i<=n;i++) printf("%d ",g[i]);
    printf("\n");
    fflush(stdout);
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++) dis[i]=-1,ID[i]=1;
    dis[1]=0;

    int tot=0;sta[++tot]=0;sta[++tot]=n;
    while(1){
        bool pd=true;
        memset(g,0,sizeof(g));
        memset(h,0,sizeof(h));
        for(int i=1;i<tot;i++){
            if(sta[i]<=sta[i+1]-3){
                pd=false;
                int mid=(sta[i+1]-sta[i]-1)>>1;
                for(int j=1;j<=n;j++)
                    if(dis[j]==sta[i]){
                        if(i%2==1) g[j]=mid;
                        else h[j]=mid;
                    }
            }
            else if(sta[i]==sta[i+1]-2){
                for(int j=1;j<=n;j++)
                    if(dis[j]==-1&&ID[j]==i) dis[j]=sta[i]+1;
            }
        }
        if(pd) break;
        query();
        scanf("%s",s1+1);
        for(int i=1;i<=n;i++)
            if(ID[i]%2==1) w1[i]=s1[i]-'0';
        for(int i=1;i<=n;i++) g[i]=h[i];
        query();
        scanf("%s",s1+1);
        for(int i=1;i<=n;i++)
            if(ID[i]%2==0) w1[i]=s1[i]-'0';

        memset(g,0,sizeof(g));
        memset(h,0,sizeof(h));
        for(int i=1;i<=tot;i++)
            if(sta[i]<=sta[i+1]-3){
                int mid=(sta[i+1]-sta[i]-1)>>1;
                for(int j=1;j<=n;j++)
                    if(dis[j]==sta[i]){
                        if(i%2==1) g[j]=mid+1;
                        else h[j]=mid+1;
                    }
            }
        query();
        scanf("%s",s2+1);
        for(int i=1;i<=n;i++)
            if(ID[i]%2==1) w2[i]=s2[i]-'0';
        for(int i=1;i<=n;i++) g[i]=h[i];
        query();
        scanf("%s",s2+1);
        for(int i=1;i<=n;i++)
            if(ID[i]%2==0) w2[i]=s2[i]-'0';
        
        memset(vis,true,sizeof(vis));
        int cnt=0;
        for(int i=1;i<=tot;i++){
            cnt++;sta2[cnt]=sta[i];
            if(i<tot&&sta[i]<=sta[i+1]-3){
                cnt++;sta2[cnt]=((sta[i+1]-sta[i]-1)>>1)+sta[i]+1;
                for(int j=1;j<=n;j++)
                    if(dis[j]==-1&&ID[j]==i&&vis[j]){
                        vis[j]=false;
                        if(w1[j]==0&&w2[j]==1) dis[j]=sta2[cnt];
                        else if(w2[j]==0) ID[j]=cnt;
                        else ID[j]=cnt-1;
                    }
            }
        }
        for(int i=1;i<=cnt;i++) sta[i]=sta2[i];
        tot=cnt;
        // for(int i=1;i<=n;i++) printf("%d ",dis[i]);printf("\n");
        // for(int i=1;i<=n;i++) printf("%d ",ID[i]);printf("\n");
    }

    for(int i=1;i<=n;i++)
        B[dis[i]].push_back(i);

    /*for(int i=0;i<n;i++){
        for(auto y:B[i]) printf("%d ",y);
        printf("\n");
    }*/

    for(int i=0;i<=2;i++){
        for(int j=0;j<=9;j++){
            int t=(1<<j);
            memset(g,0,sizeof(g));
            for(int k=i;k<n;k+=3)
                for(int l=0;l<B[k].size();l++)
                    if((l&t)) g[B[k][l]]=1;
            query();
            scanf("%s",s1+1);
            for(int k=1;k<=n;k++)
                b[j][k]=s1[k]-'0';
        }
        for(int j=2;j<=n;j++)
            if((dis[j]-1)%3==i){
                int Sum=0;
                for(int k=0;k<=9;k++)
                    if(b[k][j]) Sum=Sum+(1<<k);
                fa[j]=B[dis[j]-1][Sum];
            }
    }

    printf("!\n");
    for(int i=2;i<=n;i++) printf("%d %d\n",i,fa[i]);

    return 0;
}