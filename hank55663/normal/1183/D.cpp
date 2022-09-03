#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        map<int,int> m;
        for(int i = 0;i<n;i++){
            int x;
            scanf("%d",&x);
            m[x]++;
        }
        vector<int> v;
        for(auto it:m){
            v.pb(it.y);
        }
        sort(v.begin(),v.end());
        map<int,int> ans;
        ans[0]=0;
        for(auto it:v){
            for(int j=it;j>0;j--){
                auto it=ans.lower_bound(j);
                it--;
                ans[j]=max(ans[j],it->y+j);
                it=ans.upper_bound(j);
                while(it!=ans.end()){
                    if(it->y<ans[j]){
                        auto it2=next(it);
                        m.erase(it);
                        it=it2;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        printf("%d\n",ans.rbegin()->y);
    }
}
/*
1 
2 6 
3 5 
4
*/