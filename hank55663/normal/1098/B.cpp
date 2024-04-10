
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int row[12][300005];
int col[12][300005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<char> > c;
    c.resize(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c",&c[i][j]);
        }
    }
    char num[10]="ACGT";
    vector<string> v;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i!=j){
                string s="";
                s+=num[i];
                s+=num[j];
                v.pb(s);
               // cout<<s<<endl;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<v.size();k++){
                if(c[i][j]!=v[k][j&1])
                row[k][i]++;
                if(c[i][j]!=v[k][i&1])
                col[k][j]++;
            }
        }
    }
    vector<vector<char> > ans;
    int Min=1e9;
    pair<pii,pii> candi[6]={mp(mp(0,3),mp(8,11)),mp(mp(1,6),mp(5,10)),mp(mp(2,9),mp(4,7)),
                            mp(mp(8,11),mp(0,3)),mp(mp(5,10),mp(1,6)),mp(mp(4,7),mp(2,9))
                            };
    for(int t=0;t<6;t++){
        vector<vector<char> > res;
        res.resize(n,vector<char>(m));
        int sum=0;
        for(int i=0;i<n;i++){
            if(i&1){
                int a=candi[t].y.x;
                int b=candi[t].y.y;
                if(row[a][i]>row[b][i]){
                    swap(a,b);
                }
                sum+=row[a][i];
                for(int j=0;j<m;j++)
                res[i][j]=v[a][j&1];
            }
            else{
                int a=candi[t].x.x;
                int b=candi[t].x.y;
                if(row[a][i]>row[b][i]){
                    swap(a,b);
                }
                sum+=row[a][i];
                for(int j=0;j<m;j++)
                res[i][j]=v[a][j&1];
            }
        }
        if(sum<Min){
            Min=sum;
            ans=res;
        }
    }
    for(int t=0;t<6;t++){
        vector<vector<char> > res;
        res.resize(n,vector<char>(m));
        int sum=0;
        for(int j=0;j<m;j++){
            if(j&1){
                int a=candi[t].y.x;
                int b=candi[t].y.y;
                if(col[a][j]>col[b][j]){
                    swap(a,b);
                }
                sum+=col[a][j];
                for(int i=0;i<n;i++)
                res[i][j]=v[a][i&1];
            }
            else{
                int a=candi[t].x.x;
                int b=candi[t].x.y;
                if(col[a][j]>col[b][j]){
                    swap(a,b);
                }
                sum+=col[a][j];
                for(int i=0;i<n;i++)
                res[i][j]=v[a][i&1];
            }
        }
        if(sum<Min){
            Min=sum;
            ans=res;
        }
    }
   // printf("%d\n",Min);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
}