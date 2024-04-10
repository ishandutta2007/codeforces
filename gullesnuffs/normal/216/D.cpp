#include <stdio.h>
#include <algorithm>

using namespace std;

int threadN, bridgeN[1005], bridgeStart[1005], bridge[100005];

int main()
{
	scanf("%d", &threadN);
	for(int i=0; i < threadN; ++i){
		scanf("%d", bridgeN+i);
		if(i == 0)
			bridgeStart[i]=0;
		else
			bridgeStart[i]=bridgeStart[i-1]+bridgeN[i-1];
		for(int j=0; j < bridgeN[i]; ++j)
			scanf("%d", bridge+bridgeStart[i]+j);
		sort(bridge+bridgeStart[i], bridge+bridgeStart[i]+bridgeN[i]);
	}
	int ans=0;
	for(int i=0; i < threadN; ++i){
		int left=(i+threadN-1)%threadN, right=(i+threadN+1)%threadN;
		int leftP=0, rightP=0;
		while(leftP < bridgeN[left] && bridge[bridgeStart[left]+leftP] < bridge[bridgeStart[i]]){
			++leftP;
		}
		while(rightP < bridgeN[right] && bridge[bridgeStart[right]+rightP] < bridge[bridgeStart[i]]){
			++rightP;
		}
		for(int j=0; j < bridgeN[i]-1; ++j){
			int l=0, r=0;
			while(leftP < bridgeN[left] && bridge[bridgeStart[left]+leftP] < bridge[bridgeStart[i]+j+1]){
				++l;
				++leftP;
			}
			while(rightP < bridgeN[right] && bridge[bridgeStart[right]+rightP] < bridge[bridgeStart[i]+j+1]){
				++r;
				++rightP;
			}
			if(l != r)
				++ans;
		}
	}
	printf("%d", ans);
	return 0;
}