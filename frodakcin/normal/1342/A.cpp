#include <cstdio>
#include <algorithm>

using ll = long long;
int abs(int v) {return v<0?-v:v;}
int A, B, X, Y, T;
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", &X, &Y, &A, &B);
		if(A*2 <= B)
			printf("%lld\n", (ll)A*(abs(X)+abs(Y)));
		else
			if(X>0 ^ Y>0)
				printf("%lld\n", (ll)A*(abs(X)+abs(Y)));
			else
			{
				X = abs(X), Y = abs(Y);
				if(Y < X)
					std::swap(X, Y);
				printf("%lld\n", (ll)B*X + (ll)A*(Y-X));
			}
	}
	return 0;
}