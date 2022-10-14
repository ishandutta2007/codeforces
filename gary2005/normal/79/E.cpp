/**
 *    author:  gary
 *    created: 04.12.2021 17:35:51
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
mp p1,p2,p3,p4;
/*
1....2
.    .
.    .
3....4
*/
int n;
LL t;
int a,b,c;
int dist(mp A,mp B){
    return abs(A.FIR-B.FIR)+abs(A.SEC-B.SEC);
}
LL g(mp A,mp B,mp C){
    if(B.FIR<A.FIR) return 0;
    if(B.SEC<A.SEC) return 0;
    LL S,T;
    S=dist(A,C);
    T=dist(B,C);
    if(S>T) swap(S,T);
    return (S+T)*(T-S+1)/2;
}
bool check(int x,int y,LL t1,LL t2,LL t3,LL t4){
    // cout<<x<<' '<<y<<" "<<t1<<' '<<t2<<' '<<t3<<" "<<t4<<endl;
    if(min(min(t1,t2),min(t3,t4))<0) return false;
    if(II(x,y)==II(n,n)) return true;
    if(x<a){
        mp nw;
        nw=II(a,y);
        int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
        int sta[4]={dist(p1,II(x+1,y)),dist(p2,II(x+1,y)),dist(p3,II(x+1,y)),dist(p4,II(x+1,y))};
        LL dc[4];
        rep(i,4){
            if(fin[i]<sta[i]) swap(fin[i],sta[i]);
            dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
        }
        return check(a,y,t1-dc[0],t2-dc[1],t3-dc[2],t4-dc[3]);
    }
    if(y<b){
        mp nw;
        nw=II(x,b);
        int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
        int sta[4]={dist(p1,II(x,y+1)),dist(p2,II(x,y+1)),dist(p3,II(x,y+1)),dist(p4,II(x,y+1))};
        LL dc[4];
        rep(i,4){
            
                if(fin[i]<sta[i]) swap(fin[i],sta[i]);
            dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
        }
        return check(x,b,t1-dc[0],t2-dc[1],t3-dc[2],t4-dc[3]);
    }
    if(y>b+c-1){
        if(x<a+c-1){
            mp nw;
            nw=II(a+c-1,y);
            int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
            int sta[4]={dist(p1,II(x+1,y)),dist(p2,II(x+1,y)),dist(p3,II(x+1,y)),dist(p4,II(x+1,y))};
            LL dc[4];
            rep(i,4){
                if(fin[i]<sta[i]) swap(fin[i],sta[i]);
                dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
            }
            return check(a+c-1,y,t1-dc[0],t2-dc[1],t3-dc[2],t4-dc[3]);
        }
        if(x!=n){
            mp nw;
            nw=II(n,y);
            int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
            int sta[4]={dist(p1,II(x+1,y)),dist(p2,II(x+1,y)),dist(p3,II(x+1,y)),dist(p4,II(x+1,y))};
            LL dc[4];
            rep(i,4){
                
                if(fin[i]<sta[i]) swap(fin[i],sta[i]);
                dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
            }
            return check(n,y,t1-dc[0],t2-dc[1],t3-dc[2],t4-dc[3]);
        }
        else{
            mp nw;
            nw=II(x,n);
            int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
            int sta[4]={dist(p1,II(x,y+1)),dist(p2,II(x,y+1)),dist(p3,II(x,y+1)),dist(p4,II(x,y+1))};
            LL dc[4];
            rep(i,4){
                
                if(fin[i]<sta[i]) swap(fin[i],sta[i]);
                dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
            }
            return check(x,n,t1-dc[0],t2-dc[1],t3-dc[2],t4-dc[3]);
        }
    }
    if(x>a+c-1){
        if(y<b+c-1){
            mp nw;
            nw=II(x,b+c-1);
            int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
            int sta[4]={dist(p1,II(x,y+1)),dist(p2,II(x,y+1)),dist(p3,II(x,y+1)),dist(p4,II(x,y+1))};
            LL dc[4];
            rep(i,4){
                if(fin[i]<sta[i]) swap(fin[i],sta[i]);
                dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
            }
            return check(x,b+c-1,t1-dc[0],t2-dc[1],t3-dc[2],t4-dc[3]);
        }
        if(y!=n){
            mp nw;
            nw=II(x,n);
            int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
            int sta[4]={dist(p1,II(x,y+1)),dist(p2,II(x,y+1)),dist(p3,II(x,y+1)),dist(p4,II(x,y+1))};
            LL dc[4];
            rep(i,4){
                
                if(fin[i]<sta[i]) swap(fin[i],sta[i]);
                dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
            }
            return check(x,n,t1-dc[0],t2-dc[1],t3-dc[2],t4-dc[3]);
        }
        else{
            mp nw;
            nw=II(n,y);
            int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
            int sta[4]={dist(p1,II(x+1,y)),dist(p2,II(x+1,y)),dist(p3,II(x+1,y)),dist(p4,II(x+1,y))};
            LL dc[4];
            rep(i,4){
                
                if(fin[i]<sta[i]) swap(fin[i],sta[i]);
                dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
            }
            return check(n,y,t1-dc[0],t2-dc[1],t3-dc[2],t4-dc[3]);
        }
    }
    mp nw;
    nw=II(n,n);
    int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
    int sta[4]={dist(p1,p2)+1,dist(p2,p2)+1,dist(p3,p2)+1,dist(p4,p2)+1};
    LL dc[4];
    rep(i,4){
        // if(fin[i]<sta[i]) swap(fin[i],sta[i]);
        dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
    }
    t1-=dc[0];
    t2-=dc[1];
    t3-=dc[2];
    t4-=dc[3];
    // cout<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<endl;
    if(min(min(t1,t2),min(t3,t4))<0) return false;
    t1+=dist(p1,II(x,y));
    t2+=dist(p2,II(x,y));
    t3+=dist(p3,II(x,y));
    t4+=dist(p4,II(x,y));
    nw=p2;
    // (x,y) - > nw
    {//  23    
        nw=p2;
        int fin[4]={dist(p1,nw),dist(p2,nw),dist(p3,nw),dist(p4,nw)};
        int sta[4]={dist(p1,II(x,y)),dist(p2,II(x,y)),dist(p3,II(x,y)),dist(p4,II(x,y))};
        LL dc[4];
        rep(i,4){
                if(fin[i]<sta[i]) swap(fin[i],sta[i]);
            dc[i]=(1ll*fin[i]+sta[i])*(fin[i]-sta[i]+1)/2;
        }
        t2-=dc[1];
        t3-=dc[2];
    }
    if(min(t2,t3)<0) return false;
    LL sgm=1ll*(2*c-2)*(p2.SEC-y+p2.FIR-x+1);
    pair<LL,LL> segA,segB;
    segA=II(g(II(x,y),II(x,p2.SEC-1),p1)+g(II(x,p2.SEC),p2,p1),g(II(x,y),II(p2.FIR-1,y),p1)+g(II(p2.FIR,y),p2,p1));
    segB=II(g(II(x,y),II(x,p2.SEC-1),p4)+g(II(x,p2.SEC),p2,p4),g(II(x,y),II(p2.FIR-1,y),p4)+g(II(p2.FIR,y),p2,p4));
    swap(segB.FIR,segB.SEC);
    check_min(segA.SEC,t1-((t1%2)!=(segA.SEC%2)));
    check_min(segB.SEC,t4-((t4%2)!=(segB.SEC%2)));
    if(segA.SEC<segA.FIR||segB.SEC<segB.FIR) return false;
    return segA.FIR+segB.FIR<=sgm&&segA.SEC+segB.SEC>=sgm;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>t>>a>>b>>c;
    p1=II(a,b+c-1);
    p2=II(a+c-1,b+c-1);
    p3=II(a,b);
    p4=II(a+c-1,b);
    if(!check(1,1,t,t,t,t)) cout<<"Impossible\n";
    else{
        int x,y;
        x=y=1;
        LL t1,t2,t3,t4;
        t1=t2=t3=t4=t;
        string ans;
        rb(i,1,2*n-2){
            if(x!=n&&check(x+1,y,t1-dist(p1,II(x+1,y)),t2-dist(p2,II(x+1,y)),t3-dist(p3,II(x+1,y)),t4-dist(p4,II(x+1,y)))){
                x++;
                ans.PB('R');
            }
            else{
                y++;
                ans.PB('U');
            }
            t1-=dist(p1,II(x,y));
            t2-=dist(p2,II(x,y));
            t3-=dist(p3,II(x,y));
            t4-=dist(p4,II(x,y));
            // cout<<t1<<' '<<t2<<' '<<t3<<" "<<t4<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}