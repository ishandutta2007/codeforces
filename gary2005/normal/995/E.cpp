/**
 *    author:  gary
 *    created: 02.08.2022 08:58:36
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int u,v,p;
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%p)if(k2&1)k3=1LL*k3*k1%p;return k3;
}
int inv(int A){return quick(A,p-2);}
int doit(int x,int t,bool rev=0){
    if(rev){
        if(t<=2) t=(t-1)^1,t++;
    }
    if(t==1) (x+=1)%=p;
    if(t==2) (x+=p-1)%=p;
    if(t==3) x=inv(x);
    return x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>u>>v>>p;
    SRAND;
    while (true){
        vector<int> ans;
        int pre=random(3)+1;
        int now=u;
        now=doit(now,pre);
        ans.push_back(pre);
        vector<int> numnow;
        rb(i,1,40){
            numnow.push_back(now);
            if(i==40) break;
            int t;
            if(pre==1) t=vector<int>{1,3}[random(2)];
            else if(pre==2) t=vector<int>{2,3}[random(2)];
            else t=vector<int>{1,2}[random(2)];
            now=doit(now,t);
            pre=t;
            ans.push_back(t);
        }
        
        vector<int> sufans;
        now=v;
        pre=random(3)+1;
        now=doit(now,pre,1);
        sufans.push_back(pre);
        vector<int> sufnum;
        rb(i,1,40){
            sufnum.push_back(now);
            if(i==40) break;
            int t;
            if(pre==1) t=vector<int>{1,3}[random(2)];
            else if(pre==2) t=vector<int>{2,3}[random(2)];
            else t=vector<int>{1,2}[random(2)];
            now=doit(now,t,1);
            pre=t;
            sufans.push_back(t);
        }
        rep(i,sufnum.size()) rep(j,numnow.size()) {
            if(abs(sufnum[i]-numnow[j])<=120||abs(sufnum[i]-numnow[j]+p)<=120){
                vector<int> rest;
                rb(k,0,j) rest.push_back(ans[k]);
                now=numnow[j];
                v=sufnum[i];
                if(abs(now-v)<=160){
                    while (now>v){
                        --now;
                        rest.push_back(2);
                    }
                    while (now<v){
                        ++now;
                        rest.push_back(1);
                    }
                }
                else{
                    if(v<now){
                        while (v!=now){
                            now++;
                            now%=p;
                            rest.push_back(1);
                        }
                    }
                    else{
                        while (now!=v){
                            now--;
                            if(now==-1) now=p-1;
                            rest.push_back(2);
                        }
                    }
                }
                rl(k,i,0) rest.push_back(sufans[k]);
                cout<<rest.size()<<endl;
                for(auto it:rest) cout<<it<<" ";
                cout<<endl;
                return 0;
            }
        }
    }
    return 0;
}