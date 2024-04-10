#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 200005

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        set<string> s;
        int ans=0;
        vector<pair<string,int>> tmp;
        string res[15];
        for(int i = 0;i<n;i++){
            string it;
            cin>>it;
            res[i]=it;
            if(s.find(it)==s.end()){
                s.insert(it);
            }
            else{
                ans++;
                tmp.pb(mp(it,i));
            }
        }
        for(auto p:tmp){
            auto it=p.x;
            for(int j =0;j<10;j++){
                it[3]=j+'0';
                if(s.find(it)==s.end()){
                    s.insert(it);
                    res[p.y]=it;
                    break;
                }
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<n;i++)
            cout<<res[i]<<endl;
    }
}