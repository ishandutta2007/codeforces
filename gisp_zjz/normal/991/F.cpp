#include<bits/stdc++.h>
#define maxn 100000

using namespace std;
typedef long long ll;
ll e[maxn],r,n,a,b,c,d,h,tmp,ans,p,pp,j,jj,s,t,f,len;

int main(){
    for (int i=1;i<maxn;i++) e[i]=e[i/10]+1;
    cin >> n; e[0]=-1;
    r=0; tmp=n;
    while (tmp) r++,tmp/=10; ans=r;
    for (int i=2;i<maxn;i++){
        p=1ll*i*i; j=2;
        while (p<=n){
            s=n/p; t=n%p;
            if (s<maxn&&t<maxn&&e[t]+1+((s==1)?0:1+e[s])+e[i]+e[j]+1<ans){
                a=s; b=i; c=j; d=t;
                ans=e[t]+1+((s==1)?0:1+e[s])+e[i]+e[j]+1;
                f=0;
            }
            p=p*i; j++;
        }
    }
    for (int i=2;i<100;i++){
        p=1ll*i*i; j=2;
        while (p<=n){
            for (int ii=2;ii<1000;ii++){
                pp=1ll*ii*ii; jj=2;
                while (pp<=n){
                    for (t=0;t<10;t++) if (e[i]+e[j]+e[ii]+e[jj]+4+e[t]<ans){
                        if (p*pp+t==n||p*pp*t==n||p+pp*t==n||p+pp+t==n){
                            ans=e[i]+e[j]+e[ii]+e[jj]+4+e[t];
                            a=i; b=j; c=ii; d=jj; h=t;
                            if (p+pp+t==n) f=4;
                            else if (p+pp*t==n) f=5;
                            else if (p*pp+t==n) f=6;
                            else f=7;
                        }
                    }
                    pp=pp*ii; jj++;
                }
            }
            p=p*i; j++;
        }
    }
    //cout << ans << endl;
    if (ans==r) cout << n << endl;
    else if (f==0){
        if (a>1) printf("%d*",a);
        printf("%d^",b);
        printf("%d",c);
        if (d) printf("+%d",d); printf("\n");
    }
    else {
        cout << a << '^' << b;
        if (f&2) cout << '*'; else cout << '+';
        cout << c << '^' << d;
        if (h) {
            if (f&1) cout << '*'; else cout << '+';
            cout << h;
        }
        cout << endl;
    }
    return 0;
}