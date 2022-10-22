#include <stdio.h>
#include <set>
#include <map>
#include <iostream>

using namespace std;

set<int> values;
map<int, int> number;
int text[100005];

int main()
{
	int base, lucky, stringL, prevNonZero;
	long long sum=0;
	long long ans=0;
	scanf("%d%d%d", &base, &lucky, &stringL);
	prevNonZero=-1;
	for(int i=0; i < stringL; ++i){
		scanf("%d", text+i);
		if(lucky == base-1){
			if(text[i] == 0)
				ans -= i-prevNonZero;
			else
				prevNonZero=i;
		}
		if(lucky == 0){
			if(text[i] == 0)
				ans += i-prevNonZero;
			else
				prevNonZero=i;
		}
		else{
			if(values.find(sum) != values.end())
				++number[sum];
			else{
				values.insert(sum);
				number[sum]=1;
			}
			sum += text[i];
			sum %= base-1;
			if(values.find((sum-lucky+base-1)%(base-1)) != values.end())
				ans += number[(sum-lucky+base-1)%(base-1)];
		}
	}
	cout << ans;
	return 0;
}