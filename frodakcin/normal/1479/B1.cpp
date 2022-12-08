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
	oth.insert(-1);
	int p=-1;
	for(int i=0;i<N;++i)
	{
		if(a[i] != p)
		{
			++f;
			if(oth.size() >= 1+(oth.find(a[i])!=oth.end()))
				oth.insert(p);
		}
		else
		{
			if(oth.size() >= 1+(oth.find(a[i])!=oth.end()))
			{
				oth.clear();
				oth.insert(p);
				++f;
			}
		}
		p=a[i];
	}
	printf("%d\n", f);
	return 0;
}