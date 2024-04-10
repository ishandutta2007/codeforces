/**
 *    author:  gary
 *    created: 09.04.2022 22:35:03
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
LL f(int x,int y){
    LL len=x/y,rest=x%y;
    return len*len*(y-rest)+(len+1)*(len+1)*rest;
}
map<LL,int> line;
LL tot=0;
void doit(int x,int y){
    tot+=f(x,1)*y;
    int now=1;
    while (now<x){
        LL a,b;
        a=f(x,now),b=f(x,now+1);
        int l=now+1,r=x+1;
        while (l<r-1){
            int mid=(l+r)>>1;
            if(f(x,mid)==a+(b-a)*(mid-now)) l=mid;
            else r=mid;
        }
        line[b-a]+=(l-now)*y;
        now=l;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int pr=0;
    map<int,int> m2;
    rb(i,1,n){
        int ai;
        scanf("%d",&ai);
        ai-=pr;
        m2[ai]++;
        pr+=ai;
    }
    for(auto it:m2) doit(it.first,it.second);
    LL m;
    cin>>m;
    int rest=0;
    for(auto it:line){
        if(tot+it.first*it.second<=m){
            int l=0,r=it.second;
            while (l<r){
                int mid=(l+r)>>1;
                if(tot+it.first*mid>m) l=mid+1;
                else r=mid;
            }
            rest+=l;
            break;
        }
        else{
            rest+=it.second;
            tot+=it.first*it.second;
        }
    }
    cout<<rest<<endl;
    return 0;
}