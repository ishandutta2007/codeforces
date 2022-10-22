#include <bits/stdc++.h>
int main()
{
	char s[105];
	std::scanf("%s",s);
	int len = std::strlen(s);
	std::vector<int> Q,A;
	for (int i=0;i<len;++i)
	{
		if (s[i] == 'Q') Q.push_back(i);
		else if (s[i] == 'A') A.push_back(i);
	}
	int ans = 0,len_Q = Q.size();
	for (int x: A)
	{
		int pos = std::upper_bound(Q.begin(),Q.end(),x)-Q.begin();
		ans += pos*(len_Q-pos);
	}
	std::printf("%d\n",ans);
}