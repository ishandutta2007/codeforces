#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k,r,d,p,q,m,query,s,t,k2,lf,rt,mid;

ll solve(ll x,ll y,ll z)
{
    if (z==1) return 0;
    if ((y+1)/2<x) return z/2+solve(x-(y+1)/2,y/2,z/2); else return solve(x,(y+1)/2,z/2);
}

ll cnt(ll x,ll y,ll z)
{
    if (x==0) return 0;
    if (x==z) return y;
    if (x>z/2) return (y+1)/2+cnt(x-z/2,y/2,z/2); else return cnt(x,(y+1)/2,z/2);
}

int main()
{
    scanf("%lld%lld",&n,&k);
    if (k==1) {cout << 1 << endl; return 0;}
    if (k==2) {cout << n << endl; return 0;}
    n--; k-=2; r=1;
    while (k>r&&n/r>3){
        k-=r; r<<=1;
    }
    q=n%r; p=r-q; d=n/r;
    //cout << p << ' ' << q <<' ' << d << endl;
    if (d<3){
        lf=-1; rt=r+1;
        while (rt-lf>1){
            mid=(lf+rt)/2;
            if (mid*2-cnt(mid,p,r)>=k) rt=mid; else lf=mid;
        }
        t=rt*2-cnt(rt,p,r);
        cout << rt*3-cnt(rt,p,r)-(t!=k) << endl;
    }
    else if (d==3){
        if (k<=q) {
            t=r-1-solve(q-k+1,q,r);
            cout << k+1+t*3+1 << endl;
        }
        else {
            k-=q;
            t=(k+1)/2;
            cout << t*4-cnt(t,p,r)-(t*2!=k)*(1+(cnt(t,p,r)==cnt(t-1,p,r)));
        }
    }
    else if (d&1){
        if (k<=q) {
            t=r-1-solve(q-k+1,q,r);
            cout << k+1+d*t+d/2 << endl;
        }
        else {
            k-=q;
            t=solve(k,p,r);
            cout << (d+1)*t+(d+1)/2-k+1 << endl;
        }
    }
    else{
        t=cnt(k-1,p,r);
        cout << (d+1)*(k-1)+d/2+1-t << endl;
    }
    return 0;
}