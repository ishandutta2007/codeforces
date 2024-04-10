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
//#define next Next
int S[262144];

void add(int x,int k){
   // printf("%d %d\n",x,k);
    for(int i= x;i<262144;i+=(i&-i)){
        S[i]+=k;
    }
}
int query(int tar,int flag = 0){
    int res=0,now=0;
    for(int i = 17;i>=0;i--){
        if(flag){
         //s   printf("%d %d\n",res+(1<<i),S[res+(1<<i)]);
            if(now+S[res+(1<<i)]<tar){
                res+=(1<<i);
                now+=S[res];
            }
        }
        else{
            if(now+S[res+(1<<i)]<=tar){
                res+=(1<<i);
                now+=S[res];
            }
        }
    }
    return res;
}
int main(){
    set<int> s[256];
    int n,m;
    scanf("%d %d",&n,&m);
    char c[200005];
    scanf("%s",c+1);
    for(int i = 1;c[i]!=0;i++){
        add(i,1);
        s[c[i]].insert(i);
    }
    while(m--){
        int l,r;
        char a;
        scanf("%d %d %c",&l,&r,&a);
        l=query(l,1);
        r=query(r);
        //printf("%d %d\n",l,r);
        auto it=s[a].upper_bound(l);
        while(it!=s[a].end()&&*it<=r){
            add(*it,-1);
            auto it2=next(it);
            s[a].erase(it);
            it=it2;
        }
    }
    vector<pair<int,char> > v;
    for(int i = 0;i<256;i++){
        for(auto it:s[i]){
            v.pb(mp(it,i));
        }
    }
    sort(v.begin(),v.end());
    for(auto it:v)
        printf("%c",it.y);
    printf("\n");
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