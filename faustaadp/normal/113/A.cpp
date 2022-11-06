#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
string s;
ll n;
void gagal()
{
	cout << "NO\n";
	exit(0);
}
ll cek(string a, string b)
{
	ll lena = a.length();
	ll lenb = b.length();
	if(lena < lenb)
		return 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(ll i = 0; i < lenb; i++)
		if(a[i] != b[i])
		{
			// cout << i << " " << a << " " << b << "\n";
			return 0;
		}
	// cout << a << " " << b <<"\n";
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll las = 0;
	ll noun = 0;
	ll gender = 0;
	while(cin >> s)
	{
		n++;
		ll jenis = 0;
		if(cek(s, "lios"))jenis = 1;
		if(cek(s, "liala"))jenis = 1, gender++;
		if(cek(s, "etr"))jenis = 2;
		if(cek(s, "etra"))jenis = 2, gender++;
		if(cek(s, "initis"))jenis = 3;
		if(cek(s, "inites"))jenis = 3, gender++;	
		if(jenis == 0)gagal();
		if(jenis < las)gagal();
		las = jenis;
		if(jenis == 2)
			noun++;
	}
	// cout << noun << "_\n";
	if((noun != 1) && (n != 1))gagal();
	if(gender % n)gagal();
	cout << "YES\n";
}