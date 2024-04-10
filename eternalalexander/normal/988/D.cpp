#include <cstdio>
#include <algorithm>

int arr[300000];
int a[300000];
int v[300000];
int min,max;
int n;

int check(long long v) {
	if (v<min||v>max) return -1;
	int l=1; int r=n;
	int ans=-1;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (a[mid]==v) return mid;
		if (a[mid]<v) l=mid+1;
		if (a[mid]>v) r=mid-1;
	}return -1;
}

int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;++i) {
		scanf("%d", &arr[i]);
		min=std::min(arr[i], min);
		max=std::max(max, arr[i]);
	}std::sort(arr+1, arr+n+1);
	int cnt=1; int tail=0;
	for (int i=1;i<=n;++i) {
		if (arr[i]!=arr[i+1]||i==n) {
			a[++tail]=arr[i];
			v[tail]=cnt;
			cnt=1;
		} else cnt++;
	}
	if (n==1) {
		printf("%d\n%d", 1, arr[1]);
		return 0;
	}n=tail;
	int ans=0; int ans0=0; int ans1=0; int ans2=0;
	for (int i=1;i<=tail;++i) {
		for (long long j=1; j<=1073741824; j<<=1) {
			int lp=check(a[i]-j); int rp=check(a[i]+j);
			int sum=v[i]; if (lp>0) sum+=v[lp];
			if (rp>0) sum+=v[rp];
			if (sum>ans) {
				ans=sum;
				ans0=lp; ans1=i; ans2=rp;
			}//if (lp<0&&rp<0) break;
		}
	} printf("%d\n", ans);
	if (ans0>0) 
		for (int i=1;i<=v[ans0];++i) printf("%d ", a[ans0]);
	if (ans1>0) 
		for (int i=1;i<=v[ans1];++i) printf("%d ", a[ans1]);
	if (ans2>0) 
		for (int i=1;i<=v[ans2];++i) printf("%d ", a[ans2]);
	return 0;
}