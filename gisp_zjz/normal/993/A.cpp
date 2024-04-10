#include<bits/stdc++.h>
#define maxn 123045
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
pi a[8],w;
int c,d,e,f,p,q;
bool g;

int main(){
    for (int i=0;i<8;i++) scanf("%lld%lld",&a[i].F,&a[i].S);
    for (int i=0;i<8;i++) a[i].F*=4,a[i].S*=4;
    c=min(a[0].F,min(a[1].F,a[2].F));
    d=max(a[0].F,max(a[1].F,a[2].F));
    e=min(a[0].S,min(a[1].S,a[2].S));
    f=max(a[0].S,max(a[1].S,a[2].S));
    for (int i=4;i<8;i++) if (a[i].F<=d&&a[i].F>=c&&a[i].S<=f&&a[i].S>=e) g=1;
    w.F=0; w.S=0; for (int i=4;i<8;i++) w.F+=a[i].F,w.S+=a[i].S;
    w.F/=4; w.S/=4; if (w.F<=d&&w.F>=c&&w.S<=f&&w.S>=e) g=1;
    for (int i=0;i<8;i++) {
        p=a[i].F+a[i].S;
        q=a[i].F-a[i].S;
        a[i].F=p; a[i].S=q;
    }
    for (int i=0;i<4;i++) swap(a[i],a[i+4]);
    c=min(a[0].F,min(a[1].F,a[2].F));
    d=max(a[0].F,max(a[1].F,a[2].F));
    e=min(a[0].S,min(a[1].S,a[2].S));
    f=max(a[0].S,max(a[1].S,a[2].S));
    for (int i=4;i<8;i++) if (a[i].F<=d&&a[i].F>=c&&a[i].S<=f&&a[i].S>=e) g=1;
    w.F=0; w.S=0; for (int i=4;i<8;i++) w.F+=a[i].F,w.S+=a[i].S;
    w.F/=4; w.S/=4; if (w.F<=d&&w.F>=c&&w.S<=f&&w.S>=e) g=1;
    if (g) puts("YES"); else puts("NO");
}