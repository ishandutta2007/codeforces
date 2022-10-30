#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <array>
#include <cmath>
using namespace std;

	
	int pb, ps, pc;
	int b=0, s=0, c=0;
	int nb, ns, nc;
	long long r;

long long cost (long long k){
	long long tb, tc, ts;
	if (k*b<nb) tb=0; else tb=k*b-nb;
	if (k*c<nc) tc=0; else tc=k*c-nc;
	if (k*s<ns) ts=0; else ts=k*s-ns;
	return (tb*pb+tc*pc+ts*ps);
}
int main (){

	string str;
	cin >> str;
	for (int i=0; i< str.length(); i++){
		if (str[i]=='S') s++;
		if (str[i]=='B') b++;
		if (str[i]=='C') c++;
	}
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	if (cost(0)>r) cout << 0;
	else {
	long long sum=r/(pb*b+pc*c+ps*s);
	sum++;
	while (cost(sum)<r){
		sum=sum*10;
	}
	if (cost(sum)==r) cout << sum;
	else {
		bool flag=true;
		long long begin=0, end=sum, p;
		while (end>begin){
			p=(begin+(end-begin)/2);
			if (cost(p)>r) end=p-1;
			else if (cost(p)<r) begin=p+1;
			else {
				cout << p;
				flag=false;
				break;
			}
		}
		if (flag){
			while (cost(begin)>r) begin--;
			cout << begin;
		}
	}
	}
	return(0);
	
}