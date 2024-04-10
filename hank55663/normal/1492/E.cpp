#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<int> > v;
    for(int i = 0;i<n;i++){
        vector<int> tmp;
        for(int j = 0;j<m;j++){
            int x;
            scanf("%d",&x);
            tmp.pb(x);
        }
        v.pb(tmp);
    }
    for(int j=1;j<n;j++){
        vector<int> t;
        for(int i = 0;i<m;i++){
            if(v[0][i]!=v[j][i]){
                t.pb(i);
            }
        }
        if(t.size()==3){
             for(int a=0;a<3;a++){
                for(int b=a+1;b<3;b++){
                    swap(v[0][t[a]],v[j][t[a]]);
                    swap(v[0][t[b]],v[j][t[b]]);
                    int ok=1;
                    for(int x=0;x<n;x++){
                        if(x==j)continue;
                        int cnt=0;
                        for(int y=0;y<m;y++){
                            if(v[0][y]!=v[x][y])cnt++;
                        }
                        if(cnt>2)ok=0;
                    }
                    if(ok){
                        printf("YES\n");
                        for(int y=0;y<m;y++)printf("%d ",v[0][y]);
                        printf("\n");
                        return;
                    }
                    swap(v[0][t[a]],v[j][t[a]]);
                    swap(v[0][t[b]],v[j][t[b]]);
                }
            }
            for(int a=0;a<3;a++){
                 swap(v[0][t[a]],v[j][t[a]]);
                int ok=1;
                for(int x=0;x<n;x++){
                    if(x==j)continue;
                    int cnt=0;
                    for(int y=0;y<m;y++){
                        if(v[0][y]!=v[x][y])cnt++;
                    }
                    if(cnt>2)ok=0;
                }
                if(ok){
                    printf("YES\n");
                    for(int y=0;y<m;y++)printf("%d ",v[0][y]);
                    printf("\n");
                    return;
                }
                swap(v[0][t[a]],v[j][t[a]]);
            }
            for(int a=0;a<3;a++){
                swap(v[0][t[a]],v[j][t[a]]);
                for(int b=0;b<3;b++){
                    if(b==a)continue;
                    vector<int> val;
                    for(int x=0;x<n;x++){
                        if(x==j)continue;
                        int cnt=0;
                        for(int y=0;y<m;y++){
                            if(v[0][y]!=v[x][y])cnt++;
                        //    printf("%d ",v[x][y]);
                        }
                        if(cnt<=2)continue;
                      //  printf("!!%d %d\n",x,cnt);
                        if(cnt>=4)val.pb(0),val.pb(1e9+1);
                        if(cnt==3){
                            if(v[0][t[b]]!=v[x][t[b]])val.pb(v[x][t[b]]);
                            else val.pb(0),val.pb(1e9+1);
                        }
                    }
                    
                    sort(val.begin(),val.end());
                   // printf("%d %d %d %d\n",t[a],t[b],val[0],val.back());
                    //for(int y=0;y<m;y++)printf("%d ",v[0][y]);
                   //     printf("\n");
                    int ok=1;
                    if(val.empty());
                    else if(val[0]==val.back())v[0][t[b]]=val[0];
                    else ok=0;
                    if(ok){
                        printf("YES\n");
                        for(int y=0;y<m;y++)printf("%d ",v[0][y]);
                        printf("\n");
                        return;
                    }
                }
                swap(v[0][t[a]],v[j][t[a]]);
            }
            printf("NO\n");
            return;
        }
        else if(t.size()==4){
            for(int a=0;a<4;a++){
                for(int b=a+1;b<4;b++){
                    swap(v[0][t[a]],v[j][t[a]]);
                    swap(v[0][t[b]],v[j][t[b]]);
                    int ok=1;
                    for(int x=0;x<n;x++){
                        if(x==j)continue;
                        int cnt=0;
                        for(int y=0;y<m;y++){
                            if(v[0][y]!=v[x][y])cnt++;
                        }
                        if(cnt>2)ok=0;
                    }
                    if(ok){
                        printf("YES\n");
                        for(int y=0;y<m;y++)printf("%d ",v[0][y]);
                        printf("\n");
                        return;
                    }
                    swap(v[0][t[a]],v[j][t[a]]);
                    swap(v[0][t[b]],v[j][t[b]]);
                }
            }
            printf("NO\n");
            return;
        }
        else if(t.size()>4){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    for(int i = 0;i<m;i++)printf("%d ",v[0][i]);
    printf("\n");
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/