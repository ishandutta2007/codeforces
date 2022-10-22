#include <stdio.h>
#include <complex>

using namespace std;

complex<int> O[4];
int r[4];

int main()
{
	for(int i=0; i < 2; ++i){
		int x, y, r1, r2;
		scanf("%d%d%d%d", &x, &y, &r1, &r2);
		O[2*i]=complex<int>(x, y);
		O[2*i+1]=complex<int>(x, y);
		r[2*i]=r1;
		r[2*i+1]=r2;
	}
	int ans=0;
	int dis=norm(O[0]-O[2]);
	for(int i=0; i < 4; ++i){
		bool ok=1;
		int a[2];
		for(int j=(i<2?2:0); j < (i<2?4:2); ++j){
			a[j%2]=j;
			if(dis < (r[i]+r[j])*(r[i]+r[j])){
				if(dis > (r[i]-r[j])*(r[i]-r[j])){
					ok=0;
					break;
				}
			}
		}
		if(ok){
			if(dis <= (r[i]-r[a[0]])*(r[i]-r[a[0]]) && dis <= (r[i]-r[a[1]])*(r[i]-r[a[1]]) && r[i] <= r[a[1]] && r[a[0]] <= r[i])
				continue;
			if(dis >= (r[i]+r[a[0]])*(r[i]+r[a[0]]) && dis <= (r[i]-r[a[1]])*(r[i]-r[a[1]]) && r[i] <= r[a[1]])
				continue;
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}