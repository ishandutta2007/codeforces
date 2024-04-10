#include <stdio.h>
#include <map>

using namespace std;

int cardN, card[100005][2];

map<int, int> colorN;

int main()
{
	scanf("%d", &cardN);
	for(int i=0; i < cardN; ++i){
		scanf("%d%d", card[i], card[i]+1);
		if(card[i][0] == card[i][1])
			colorN[card[i][0]]++;
		else{
			colorN[card[i][0]]++;
			colorN[card[i][1]]++;
		}
	}
	int ans=-1;
	for(map<int, int>::iterator it=colorN.begin(); it != colorN.end(); ++it){
		if(it->second*2 >= cardN){
			int change=(cardN+1)/2;
			for(int i=0; i < cardN; ++i)
				if(card[i][0] == it->first)
					--change;
			if(change < 0)
				change=0;
			if(ans == -1 || change < ans)
				ans=change;
		}
	}
	printf("%d", ans);
	return 0;
}