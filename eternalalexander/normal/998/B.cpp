#include <cstdio>
int arr[102];
int ct[102]={0};
int sum[102]={0};
int abs(int x) {
	if (x<0) return -x;
	return x;
}
int main() {
	int n, b;
	scanf("%d %d", &n, &b);
	for (int i=1;i<=n;++i) {
		scanf("%d", &arr[i]); sum[i]=sum[i-1]+(arr[i]%2==0?-1:1);
	}int ans=0;
	//for (int i=1;i<=n;++i) printf("%d ", sum[i]);
	while (b>0) {
		int min=99999999;
		int cut=0;
		for (int i=1;i<n;++i) {
			if (sum[i]==0&&abs(arr[i+1]-arr[i])<min&&ct[i]==0) {
				cut=i; min=abs(arr[i+1]-arr[i]);
			}
		}if (cut==0) {
			break;
		}if (min<=b) {
			b-=min;
			ans+=1;
			ct[cut]=1;
		}else break;
	}printf("%d", ans);
	return 0;
}