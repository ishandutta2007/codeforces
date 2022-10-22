#include <bits/stdc++.h>

using namespace std;
int l[6];

int main(){
	int p[6]={0,1,2,3,4,5};
	for(int i=0; i < 6; ++i){
		scanf("%d", l+i);
	}
	bool bear=0, elephant=0;
	sort(l, l+6);
	do{
		if(l[1]==l[0]&&l[2]==l[0]&&l[3]==l[0]&&l[4]<l[5])
			bear=1;
		if(l[1]==l[0]&&l[2]==l[0]&&l[3]==l[0]&&l[4]==l[5])
			elephant=1;
	}while(next_permutation(l, l+6));
	if(bear)
		puts("Bear");
	else if(elephant)
		puts("Elephant");
	else
		puts("Alien");
}