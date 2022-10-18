#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <string.h>

using namespace std;

int arr[100005];

long long gcd(long long a,long long b) { return b==0 ? a : gcd(b,a%b); }

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    long long sum=0,p=0,q=n;
    for(int i=0;i<n;++i) {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    sort(arr,arr+n);
    long long tmp=sum;
    for(int i=0;i<n;++i) {
        sum-=arr[i];
        p+=sum-1LL*arr[i]*(n-1-i);
    }
    p=2*p+tmp;
    long long g=gcd(p,q); p/=g; q/=g;
    cout << p << " " << q << endl;
    return 0;
}