#include<bits/stdc++.h>
using namespace std;
int a,b,c,aa,bb,cc,ttm;
char ca[2]={'R','L'};
int main()
{
	cin>>a>>b>>c;
	cc=c%2;
	aa=ceil((double)((double)c/(double)(b*2)));
	ttm=c-((aa-1)*2*b);
	bb=ceil((double)((double)ttm/(double)(2)));
	cout<<aa<<" "<<bb<<" "<<ca[cc]<<endl;
}