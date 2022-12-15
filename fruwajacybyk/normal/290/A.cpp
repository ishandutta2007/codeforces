#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;

string t[]={
"Washington ",
"Adams ",
"Jefferson ",
"Madison ",
"Monroe ",
"Adams",
"Jackson ",
"Van Buren",
"Harrison",
"Tyler ",
"Polk ",
"Taylor ",
"Fillmore",
"Pierce ",
"Buchanan",
"Lincoln ",
"Johnson ",
"Grant",
"Hayes",
"Garfield",
"Arthur ",
"Cleveland ",
"Harrison ",
"Cleveland ",
"McKinley ",
"Roosevelt ",
"Taft ",
"Wilson ",
"Harding",
"Coolidge ",
"Hoover",
"Roosevelt ",
"Truman ",
"Eisenhower ",
"Kennedy ",
"Johnson ",
"Nixon ",
"Ford ",
"Carter ",
"Reagan ",
"Bush ",
"Clinton ",
"Bush ",
"Obama"};

int main(){
	int a,b;
	cin>>a;
	cout<<t[a-1]<<endl;
	return 0;
}