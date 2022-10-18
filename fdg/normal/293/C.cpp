#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>

using namespace std;

int Sqrt(long long n) {
    int l=0,r=1000000000;
    while(r-l>1) {
        long long m=(l+r)>>1;
        if (m*m<=n) l=m;
        else r=m;
    }
    return 1LL*l*l==n ? l : -1;
}

set < pair<int,int> > f;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    long long n,ans=0;
    cin >> n;
    if (n%3!=0) {
        puts("0");
        return 0;
    }
    n/=3;
    for(int k=2;1LL*k*k*k<=n;++k) {
        if (n%k==0)
            for(int a=1;a<k;++a) {
                int b=k-a;
                long long d=n/k;
                long long D=1LL*k*k-4LL*a*b+4*d;
                int s=sqrt(0.0+D);//Sqrt(D);
                if (1LL*s*s==D) {//D>=0&&s!=-1) {
                    int c=(-k+s);
                    if (c%2==0) {
                        c>>=1;
//                      cout << a << "  " << b << " " << c << endl;
                        int arr[]={a,b,c};
                        sort(arr,arr+3);
                        if (!f.count(make_pair(arr[0],arr[1]))) {
                            if (arr[0]==arr[2]) ++ans;
                            else if (arr[0]==arr[1]||arr[1]==arr[2]) ans+=3;
                            else ans+=6;
                            f.insert(make_pair(arr[0],arr[1]));
                        }
                    }
                }
            }
    }
    cout << ans << endl;
//  cout << clock() << endl;
    return 0;
}