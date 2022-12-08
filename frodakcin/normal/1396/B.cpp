//will this work?
#include <cstdio>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return a>b?a=b,1:0;}

int T, N, sum, max, a[110];

int main()
{
	scanf("%d", &T);
	for(int tc=1;tc<=T;++tc)
	{
		scanf("%d", &N);
		sum=max=0;
		for(int i=0;i<N;++i)
			scanf("%d", a+i), sum+=a[i], ckmax(max, a[i]);
		if(max > sum - max)
			printf("T\n");
		else
			if(sum&1)
				printf("T\n");
			else
				printf("HL\n");
	}
	return 0;
}