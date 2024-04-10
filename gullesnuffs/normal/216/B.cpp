
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> archenemy[200];

int main()
{
	int studentN, archN;
	scanf("%d%d", &studentN, &archN);
	for(int i=0; i < archN; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		archenemy[a].push_back(b);
		archenemy[b].push_back(a);
	}
	int ans=0;
	for(int i=0; i < studentN; ++i){
		if(archenemy[i].size() < 2)
			continue;
		int a=archenemy[i][0], p=i, j;
		for(j=1; a != i; ++j){
			if(archenemy[a].size() < 2)
				break;
			if(a < i)
				break;
			int b;
			if(archenemy[a][0] == p)
				b=archenemy[a][1];
			else
				b=archenemy[a][0];
			p=a;
			a=b;
		}
		if(a == i && j%2)
			++ans;
	}
	if((studentN-ans)%2)
		++ans;
	printf("%d", ans);
	return 0;
}