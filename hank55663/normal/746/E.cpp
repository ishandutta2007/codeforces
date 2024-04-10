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
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[200005];
    set<int> s;
    vector<int> even,odd;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(s.find(a[i])!=s.end()){
            even.pb(i);
            a[i]=-1;
        }
        else{
            s.insert(a[i]);
        }
    }
    if(n%2!=0){
        printf("-1\n");
    }
    else{
        vector<int> v[2];
        for(int i = 1;i<=n;i++){
            if(a[i]!=-1){
                v[a[i]&1].pb(i);
            }
        }
        while(even.size()+v[0].size()>odd.size()+v[1].size()){
            if(even.size()){
                odd.pb(even.back());
                even.pop_back();
            }
            else{
                odd.pb(v[0].back());
                v[0].pop_back();
            }
        }
        while(even.size()+v[0].size()<odd.size()+v[1].size()){
            if(odd.size()){
                even.pb(odd.back());
                odd.pop_back();
            }
            else{
                even.pb(v[1].back());
                v[1].pop_back();
            }
        }
        int res=odd.size()+even.size();
        int now=1;
        for(auto it:odd){
            //printf("%d\n",it);
            while(s.find(now)!=s.end())now+=2;
            a[it]=now;
            s.insert(now);
        }
        if(now>m){
            printf("-1\n");
            return 0;
        }
        now=0;
        s.insert(0);
        for(auto it:even){
            while(s.find(now)!=s.end())now+=2;
            a[it]=now;
            //now+=2;
            s.insert(now);
        }
        if(now>m){
            printf("-1\n");
            return 0;
        }printf("%d\n",res);
        for(int i =1;i<=n;i++){
            printf("%d ",a[i]);
        }
    }

}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */