#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
long long n, x, y, c;
long long c2(long long n) {return n*(n+1)/2; }
long long cnt(long long t) {
	long long sum=c2(t+1)*4-4*(t+1)+1;
	if (t>=x) sum-=c2(t-x+1)*2-(t-x+1);
	if (t>n-x) sum-=c2(t-n+x)*2-(t-n+x);
	if (t>=y) sum-=c2(t-y+1)*2-(t-y+1);
	if (t>n-y) sum-=c2(t-n+y)*2-(t-n+y);
	if (t>=x+y) sum+=c2(t-x-y+1);
	if (t>=n-x+1+y) sum+=c2(t-n+x-y);
	if (t>=n-y+1+x) sum+=c2(t-n+y-x);
	if (t>=n-y+n-x+2) sum+=c2(t-n+y-n+x-1);
	return sum;
}
long long ans (long long min, long long max) {
	if (min==max) return min;
	long long mid=(min+max)/2;
	if (cnt(mid)>=c) return ans(min, mid);
	else return ans(mid+1, max);
}
int main(){
	cin >> n >> x >> y >> c;
	cout << ans(0, 2*n);
    return 0;
}