#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
pll gcd(LL a, LL b){
    if(b == 0) return mp(1, 0);
    else{
        LL p = a / b;
        pll q = gcd(b, a % b);
        return make_pair(q.y, q.x - q.y * p);
    }
}
vector<LL> v;
set<LL> s;
vector<pair<pll,char> > op;
void build(){
   // int a=rand()%v.size(),b=rand()%v.size();
    int a=v.back();
    vector<int> tmp;
    for(auto b:v){
        if(s.find(a+b)==s.end()){
            if(a+b<1e9){
                op.pb(mp(mp(a,b),'+'));
                tmp.pb(a+b);
                //v.pb(a+b);
                s.insert(a+b);
            }
        }
        if(a!=b&&s.find(a^b)==s.end()){
            if((a^b)<1e9){
                op.pb(mp(mp(a,b),'^'));
                tmp.pb(a^b);
                //v.pb(a^b);
                s.insert(a^b);
            }
        }
    }
    for(auto it:tmp)v.pb(it);
    /*
    if(s.find(v[a]+v[b])==s.end()){
        if(v[a]+v[b]<1e9){
            op.pb(mp(mp(v[a],v[b]),'+'));
            v.pb(v[a]+v[b]);
            s.insert(v[a]+v[b]);
        }
    }
    if(a!=b&&s.find(v[a]^v[b])==s.end()){
        op.pb(mp(mp(v[a],v[b]),'^'));
        v.pb(v[a]^v[b]);
        s.insert(v[a]^v[b]);
    }*/
}
LL build(LL a,LL b){
    if(a==1)return b;
    if(a&1){
        op.pb(mp(mp(b,b),'+'));
        LL res=build(a/2,b*2);
        op.pb(mp(mp(res,b),'+'));
        res+=b;
        return res;
    } 
    else{
        op.pb(mp(mp(b,b),'+'));
        
        return build(a/2,b*2);
        
    }
}
int now=3;
void solve(){
    int x=now;
    now+=2;
    scanf("%d",&x);
    for(int i = 1;i<=1000000;i++){
        LL a=x*1ll*i;
        LL b=x*1ll*(i-1);
        LL c=a^b;
        if(__gcd(a,c)==1){
           // return;
            pll p=gcd(a,c);
            p.x=abs(p.x);
            p.y=abs(p.y);
            if((__int128)p.x*a<5e18)
            {
                
                build(i,x);
                build(i-1,x);
                op.pb(mp(mp(a,b),'^'));
                LL aa=build(p.x,a);
                LL bb=build(p.y,c);
                if(aa>bb)swap(aa,bb);
                if(aa%2==1){
                    op.pb(mp(mp(aa,x),'+'));
                    op.pb(mp(mp(bb,x),'+'));
                    aa+=x;
                    bb+=x;
                }
                op.pb(mp(mp(aa,bb),'^'));
                printf("%d\n",op.size());
                for(auto it:op){
                    printf("%lld %c %lld\n",it.x.x,it.y,it.x.y);
                }
                return;
            }
        }
        if(__gcd(b,c)==1){
         //   return;
            pll p=gcd(b,c);
            p.x=abs(p.x);
            p.y=abs(p.y);
            if((__int128)p.x*a<5e18){
                build(i,x);
                build(i-1,x);
                op.pb(mp(mp(a,b),'^'));
                LL aa=build(p.x,b);
                LL bb=build(p.y,c);
                if(aa>bb)swap(aa,bb);
                if(aa%2==1){
                    op.pb(mp(mp(aa,x),'+'));
                    op.pb(mp(mp(bb,x),'+'));
                    aa+=x;
                    bb+=x;
                }
                op.pb(mp(mp(aa,bb),'^'));
                 printf("%d\n",op.size());
                for(auto it:op){
                    printf("%lld %c %lld\n",it.x.x,it.y,it.x.y);
                }
                return;
            }
        }
    }
    //printf("%d\n",x);
    assert(0);

    v.pb(x);
    for(int i = 0;i<12;i++){
        if(v.size()<5000)
        build();
    }
    printf("%d\n",v.size());
    for(int i = 0;i<v.size();i++){
        for(int j = i+1;j<v.size();j++){
            if(__gcd(v[i],v[j])==1){
                pii p=gcd(v[i],v[j]);
                p.x=abs(p.x);
                p.y=abs(p.y);
                LL a=build(p.x,v[i]);
                LL b=build(p.y,v[j]);
                if(a>b)swap(a,b);
                if(a%2==1){
                    op.pb(mp(mp(a,x),'+'));
                    op.pb(mp(mp(b,x),'+'));
                    a+=x;
                    b+=x;
                }
                op.pb(mp(mp(a,b),'^'));
                printf("%d\n",op.size());
              /*  for(auto it:op){
                    printf("%lld %c %lld\n",it.x.x,it.y,it.x.y);
                }*/
               // printf("%d %d %d\n",x,v[i],v[j]);
                v.clear();
                s.clear();
                op.clear();
                return;
               // goto end;
            }
        }
    }
    printf("%d\n",x);
    assert(0);
}
int main(){
    int t=1;//000000;
   // scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/