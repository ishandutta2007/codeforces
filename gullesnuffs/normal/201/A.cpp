#include <stdio.h>

using namespace std;

int main()
{
	int sharp;
	scanf("%d", &sharp);
	if(sharp%4 == 0){
		int n;
		for(n=0; true; ++n){
			int s;
			if(n%2)
				s=(n*n-1)/2;
			else
				s=((n-2)*(n-2))/2;
			if(s >= sharp)
				break;
		}
		printf("%d", n);
		return 0;
	}
	if(sharp%4 == 2){
		int n;
		for(n=1; true; n += 2){
			int s;
			s=(n*n-1)/2;
			if(s >= sharp)
				break;
		}
		printf("%d", n);
		return 0;
	}
	if(sharp%2 == 1){
		int n;
		for(n=1; true; n += 2){
			int s;
			s=(n*n+1)/2;
			if(s >= sharp && (sharp%4 == 1 || n >= 5))
				break;
		}
		printf("%d", n);
		return 0;
	}
	return 0;
}