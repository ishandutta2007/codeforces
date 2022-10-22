
#include <stdio.h>
#include <vector>

using namespace std;

int partN, house[200];
vector<int> needed[200];
bool solved[200];

bool done(){
	for(int i=0; i < partN; ++i)
		if(!solved[i])
			return 0;
	return 1;
}

int main()
{
	scanf("%d", &partN);
	for(int i=0; i < partN; ++i)
		scanf("%d", house+i);
	for(int i=0; i < partN; ++i){
		int k;
		scanf("%d", &k);
		for(int j=0; j < k; ++j){
			int n;
			scanf("%d", &n);
			--n;
			needed[i].push_back(n);
		}
	}
	int best=1000000000, curHouse, time;
	for(int start=1; start <= 3; ++start){
		for(int i=0; i < partN; ++i){
			solved[i]=0;
		}
		curHouse=start;
		time=0;
		while(!done()){
			++time;
			bool added=1;
			while(added){
				added=0;
				for(int i=0; i < partN; ++i){
					if(house[i] != curHouse)
						continue;
					if(solved[i])
						continue;
					bool ok=1;
					for(int j=0; j < needed[i].size(); ++j){
						if(!solved[needed[i][j]]){
							ok=0;
							break;
						}
					}
					if(ok){
						++time;
						solved[i]=1;
						added=1;
					}
				}
			}
			curHouse=(curHouse)%3+1;
		}
		--time;
		if(time < best)
			best=time;
	}
	printf("%d", best);
	return 0;
}