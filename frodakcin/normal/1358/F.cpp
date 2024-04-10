#include <cstdio>
#include <algorithm>

const int MAX = 2e5;
const int MN = 2e5+10;
const int ML = 5e5;
using ll = long long;
int N, F;
ll cnt, a[MN], b[MN];
char f[ML+10];
bool good;

void fail() {printf("IMPOSSIBLE\n");}
void app(char x){if(F<ML) f[F++] = x; cnt+=x=='P';}
void appk(char x, ll k)
{
	for(;k&&F<ML;--k)
		app(x);
	if(x=='P') cnt+=k;
}

int main(void)
{
	scanf("%d", &N);
	for(int i=0;i<N;++i) scanf("%lld", a+i);
	for(int i=0;i<N;++i) scanf("%lld", b+i);
	if(N==1)
	{
		if(a[0] == b[0]) printf("SMALL\n0\n\n");
		else fail();
		return 0;
	}
	ll al = std::max(a[0], a[N-1]), as = std::min(a[0], a[N-1]);
	if(N==2)
	{
		for(;;)
		{
			if(b[1]<b[0]) std::swap(b[0], b[1]), app('R');
			if(b[0] < as || b[1] <= al) break;
			if(b[0] >= al)
			{
				if(b[1]%b[0])
				{
					appk('P', b[1]/b[0]);
					b[1]%=b[0];
				}
				else
				{
					appk('P', b[1]/b[0]-1);
					b[1] = b[0];
					break;
				}
			}
			else
			{
				if(b[0] != as) break;
				if((b[1]-al)%as) break;
				appk('P', (b[1]-al)/as);
				b[1]=al;
				break;
			}
		}
	}
	else
	{
		//N >= 3: straight simulate
		for(;;)
		{
			if(b[0] > b[N-1]) std::reverse(b, b+N), app('R');
			//for(int i=0;i<N;++i) printf("%lld%c", b[i], " \n"[i+1==N]);
			if(b[0] < as || b[N-1] <= al)
				break;
			app('P');
			for(int i=N-1;i>0;--i)
				if((b[i]-=b[i-1])<=0) return fail(), 0;
		}
	}
	good=1;
	for(int i=0;good&&i<N;++i)
		if(a[i]!=b[i])
			good=0;
	if(!good)
	{
		good=1;
		app('R');
		std::reverse(b, b+N);
		for(int i=0;good&&i<N;++i)
			if(a[i]!=b[i])
				good=0;
	}
	if(!good) return fail(), 0;
	std::reverse(f, f+F);
	if(cnt > MAX)
		printf("BIG\n%lld\n", cnt);
	else
		printf("SMALL\n%d\n%s\n", F, f);
	return 0;
}