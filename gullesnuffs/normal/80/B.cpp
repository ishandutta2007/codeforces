#include <bits/stdc++.h>

using namespace std;

int main(){
	char hhmm[6];
	scanf("%s", hhmm);
	double h=(hhmm[0]-'0')*10+hhmm[1]-'0';
	double m=(hhmm[3]-'0')*10+hhmm[4]-'0';
	while(h >= 12)
		h -= 12;
	double p1=h/12+m/(12*60);
	printf("%.9lf %.9lf\n", p1*360, m*6);
}