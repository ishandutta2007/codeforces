#include <stdio.h>

using namespace std;

int driftN, x[200], y[200];
bool visited[200];

int main()
{
	scanf("%d", &driftN);
	for(int i=0; i < driftN; ++i){
		scanf("%d%d", x+i, y+i);
		visited[i]=0;
	}
	int ans=0;
	for(int i=0; i < driftN; ++i){
		if(!visited[i]){
			++ans;
			visited[i]=1;
			int list[200], listPos=0, listN=1;
			list[0]=i;
			while(listPos < listN){
				for(int j=0; j < driftN; ++j){
					if(x[j] == x[list[listPos]] || y[j] == y[list[listPos]]){
						if(!visited[j]){
							list[listN++]=j;
							visited[j]=1;
						}
					}
				}
				++listPos;
			}
		}
	}
	printf("%d", ans-1);
	return 0;
}