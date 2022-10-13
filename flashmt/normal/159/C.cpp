#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d[26][200200],cnt[26],cur[26];
string s,t;


void add(int ch,int x)
{
	while (x<=cnt[ch]) d[ch][x]++, x+=x&-x;		
}

int get(int ch,int x)
{
	int res=0;
	while (x) res+=d[ch][x], x-=x&-x;
	return res;
}

int main()
{
	int m,x,k;
	cin >> k >> s >> m;
	for (int i=0;i<int(s.size());i++) cnt[s[i]-'a']+=k;
			
	while (m--) 
	{
		cin >> x >> t;
		int ch=t[0]-'a',low=1,high=cnt[ch],found=0;
		while (low<=high)
		{
			int mid=(low+high)/2;
			if (mid-get(ch,mid)>=x) found=mid, high=mid-1;
			else low=mid+1;
		}
		add(ch,found);
	}	
	
	while (k--)
		for (int i=0;i<int(s.size());i++)
		{
			int ch=s[i]-'a';
			if (get(ch,cur[ch])==get(ch,++cur[ch])) cout << s[i];
		}
}