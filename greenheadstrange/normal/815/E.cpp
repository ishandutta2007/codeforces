#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define ll long long
using namespace std;
struct th
{
	ll num, len, ans;
	th(ll a, ll b){num = a, len = b;}
	bool operator < (const th &a)const
	{
		if(num != a.num) return num < a.num;
		return len < a.len;
	}
};
set <th> ans;
ll get(ll len, ll num)
{
	th new1 = th(num, len);
	set <th> :: iterator it = ans.find(new1);
	if(it != ans.end()) return (*it).ans;
	ll mid = (1 + len) >> 1;
	new1.ans = 0;
	if(mid - 1 >= num) 
		new1.ans = 1 + get(mid, num) + get(len - mid + 1, num);
	ans.insert(new1);
//'	cout<<len<<" "<<num<<" "<<new1.ans<<endl;
	return new1.ans;
}
ll gpl(ll len, ll num, ll id)
{
	if(len == 1) return 1;
	ll mid = (1 + len) >> 1;
	ll ans = 0;
	if(id == 1) ans = mid;
	else
	{
		ll lans = get(mid, num);
		ll rans = get(len - mid + 1, num + 1);
		if(lans + rans + 1 >= id && lans)
			ans = gpl(mid, num, id - rans - 1);
		else ans = mid - 1 + gpl(len - mid + 1, num, id - lans - 1);
	}
	return ans;
}
int main()
{
	ll n, k;
	scanf("%I64d%I64d", &n, &k);
	if(k == 1)
	{
		puts("1\n");
		return 0;
	 } 
	 if(k == 2)
	 {
	 	printf("%I64d\n", n);
	 	return 0;
	 }
	 k -= 2;
	ll l = 0, r = n;
	while(l < r)
	{	//find the last which >= k
		ll mid = (l + r) >> 1;
		if(get(n, mid + 1) >= k) l = mid + 1;
		else r = mid;
	} 
	printf("%I64d\n", gpl(n, l, k));
	return 0;
}