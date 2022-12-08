#include <cstdio>
#include <algorithm>
#include <set>

int main()
{
	int N;
	scanf("%d", &N);
	std::set<int> oth;
	int a[N];
	int f=0;
	for(int i=0;i<N;++i) scanf("%d", a+i);
	int p=-1;
	for(int i=0;i<N;++i)
	{
		if(a[i] != p)
		{
			if(oth.find(a[i])==oth.end()) // not in other
			{
				++f;
				oth.insert(p);
			}
			else
			{
				oth.clear();
				oth.insert(p);
			}
		}
		p=a[i];
	}
	printf("%d\n", f);
	return 0;
}