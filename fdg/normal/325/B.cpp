#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

long long Sqrt(unsigned long long n) {
    long long l=0,r=3000000000;
    while(r-l>1) {
        long long m=(l+r)>>1;
        if (1ull*m*m<=n) l=m;
        else r=m;
    }
    return l;
}

int get(int n) {
    int ret=0;
    while(n%2==0) ret+=n/2,n/=2;
    return ret+n*(n-1)/2;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    long long n;
    cin >> n;
    set <long long> f;
    for(int d=0;d<30;++d) {
        long long a=1,b=(1LL<<(d+1))-3,c=-2*n;
        unsigned long long D=b*b-4*a*c;
        if (D>=0) {
            long long s=Sqrt(D);
            if (s*s==D) {
                long long x=(-b+s)/2/a;
                if ((x&1)&&(s-b)%(2*a)==0) {
                    x<<=d;
                    f.insert(x);
                }
            }
        }
    }
    for(int i=1;i<=1000000;i+=2) {
        long long x=i,ret=x*(x-1)/2;
        while(ret<n) ret+=x,x<<=1;
        if (ret==n) f.insert(x);
    }
    for(set <long long>::iterator it=f.begin();it!=f.end();++it) {
//      if (get(*it)!=n) cout << "fail\n";
        cout << *it << endl;
    }
    if (f.size()==0) puts("-1");
/*
    for(int i=1;i<=100;++i)
        cout << i << "  " << get(i) << endl;
*/  return 0;
}