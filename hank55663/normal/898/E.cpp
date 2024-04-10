#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int n;
    scanf("%d",&n);
    int sq=0,nsq=0;
    vector<int> v;
    vector<int> v2;
    set<int> s;
    for(int i = 0;i<=4e4;i++){
        s.insert(i*i);
    }
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(s.find(x)!=s.end()){
            sq++;
            if(x==0)
            v2.pb(2);
            else
            v2.pb(1);
        }
        else{
            auto it=s.lower_bound(x);
            auto it2=it;
            it2--;
            v.pb(min(*it-x,x-*it2));
            nsq++;
        }
    }

    if(nsq==sq){
        printf("0\n");
    }
    else if(sq>nsq){
        sort(v2.begin(),v2.end());
        LL ans=0;
        for(int i = 0;i<(sq-nsq)/2;i++)
            ans+=v2[i];
        printf("%lld\n",ans);
    }
    else{
        sort(v.begin(),v.end());
        LL ans=0;
        for(int i = 0;i<(nsq-sq)/2;i++)
        ans+=v[i];
        printf("%lld\n",ans);
    }
}
/*
1 8 18
2 7 17
3 6 16
4 5 15
5 14
6 13
7 12
8 11
9 10
10 19
11 18
12 17
13 16
14 15
0 ~ 2345 2
2346 ~ 9999 1
 9999
12345
*/