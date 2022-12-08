#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>

const int MN = 2.5e5+10;

int N, M, a[MN], ok[MN];

int diff(int *a, int *b)
{
	int f=0;
	for(int i=0;i<M;++i)
		f += a[i]!=b[i];
	return f;
}

bool check(int *v)
{
	for(int i=0;i<N;++i)
		if(diff(a+i*M, v)>2) return 0;
	return 1;
}

bool check(int *v, int flex)
{
	int force=-1;
	for(int i=0;i<N;++i)
	{
		int d=0;
		for(int j=0;j<M;++j)
			if(j!=flex)
				d += a[i*M+j]!=v[j];
		if(d>2) return 0;
		if(d==2)
		{
			if(force!=-1 && force!=a[i*M+flex]) return 0;
			else force=a[i*M+flex];
		}
	}
	if(force==-1) force=69;
	ok[flex]=force;
	return 1;
}

void ans(int *a)
{
	printf("Yes\n");
	for(int i=0;i<M;++i) printf("%d%c", a[i], " \n"[i+1==M]);
}

void fail() {printf("No\n");}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<N*M;++i)
		scanf("%d", a+i);

	int x, d;
	for(x=1;x<N;++x)
		if((d=diff(a, a+x*M))>2)
			break;

	if(x==N) return ans(a), 0;
	if(d>4) return fail(), 0;

	memcpy(ok, a, M*sizeof*ok);
	std::vector<int> loc;
	for(int i=0;i<M;++i)
		if(a[i]!=a[x*M+i])
			loc.push_back(i);
	assert(loc.size()==d);

	if(d==3)
	{
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				if(i!=j)
				{
					ok[loc[j]]=a[x*M+loc[j]];
					if(check(ok, loc[i]))
						return ans(ok), 0;
					//ok[loc[i]]=a[loc[i]]; //not necessary
					ok[loc[j]]=a[loc[j]];
				}
	}
	else if(d==4)
	{
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				if(i!=j)
				{
					ok[loc[i]]=a[x*M+loc[i]];
					ok[loc[j]]=a[x*M+loc[j]];
					if(check(ok))
						return ans(ok), 0;
					ok[loc[i]]=a[loc[i]];
					ok[loc[j]]=a[loc[j]];
				}
	}

	return fail(), 0;
}