#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef double d;
typedef pair<d,d> P;
typedef pair<d,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	int Number;
	cin >> Number;
	priority_queue<P1>que;
	for(int i=0;i<Number;i++){
		double len,prob; cin >> len >> prob;
		que.push(mp(len*prob/((100.0-prob)!=0.0?(100.0-prob):0.001),mp(len,prob)));
	}
	double MaximumExpectedLength=0.0,ExpectedRepeatLength=0.0;
	while(!que.empty()){
		P1 p1=que.top(); que.pop();
		MaximumExpectedLength+=p1.second.first;
		MaximumExpectedLength+=ExpectedRepeatLength*(100.0-p1.second.second)/100.0;
		ExpectedRepeatLength+=p1.second.first*p1.second.second/100.0;
	}
	printf("%.10lf\n",MaximumExpectedLength);
	return 0;
}