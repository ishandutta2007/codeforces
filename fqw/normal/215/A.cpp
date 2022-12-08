#include <cstdio>
using namespace std;

int main() {
	int n, m, a[55], b[55];
	scanf("%d", &n); for(int i=0; i<n; ++i) scanf("%d", &a[i]);
	scanf("%d", &m); for(int i=0; i<m; ++i) scanf("%d", &b[i]);
	int max=0, cnt;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(b[j]%a[i] == 0)
				if(b[j]/a[i]>max) max=b[j]/a[i], cnt=1;
				else if(b[j]/a[i]==max) ++cnt;
	printf("%d\n", cnt);
	//printf("max=%d\n",max);
	return 0;
}