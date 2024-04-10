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
        map<int,pii> m;
        for(int i = 0;i<n;i++){
            int x,f;
            scanf("%d %d",&x,&f);
            m[x].x++;
            if(f){
                m[x].y++;
            }
        }
        vector<pii> v;
        for(auto it:m){
            v.pb(it.y);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int last=1e9;
        int sum=0;
        vector<int> ans;
        for(auto it:v){
            int add=min(last-1,it.x);
            sum+=add;
            last=add;
            if(add==0)break;
            ans.pb(add);
        }
        printf("%d",sum);
        multiset<int> s;
        int now=0;
        int ans2=0;
        for(auto it:ans){
            //printf("%d",it);
            while(now!=v.size()&&v[now].x>=it){
                s.insert(v[now].y);
                now++;
            }
            //printf(" %d %d\n",now,s.size());
            ans2+=min(*s.rbegin(),it);
            s.erase(s.find(*s.rbegin()));
        }
        printf(" %d\n",ans2);
    }
}
/*
1 
2 6 
3 5 
4
*/