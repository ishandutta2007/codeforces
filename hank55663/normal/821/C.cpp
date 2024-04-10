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
#define N 200005
#define rank Rank
#define index Index
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    set<int> s;
    int ans=0;
    for(int i = 0;i<n*2;i++){
        char c[10];
        scanf("%s",c);
        if(c[0]=='a'){
            int x;
            scanf("%d",&x);
            v.pb(x);
            s.insert(x);
        }
        else{
            if(v.empty()){
                s.erase(s.begin());
            }
            else if(v.back()==*s.begin()){
                v.pop_back();
                s.erase(s.begin());
            }
            else{
                v.clear();
                ans++;
                s.erase(s.begin());
            }
        }
    }
    printf("%d\n",ans);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
11010101
*/