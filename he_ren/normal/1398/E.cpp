#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

set<int> fH, fL, lH, lL;
ll ans = 0;

int erase_both(void)
{
	int res = 0;
	if(!lH.empty()) ans -= *lH.begin(), lL.insert(*lH.begin()), lH.erase(lH.begin()), ++res;
	if(!fH.empty()) ans -= *fH.begin(), fL.insert(*fH.begin()), fH.erase(fH.begin()), ++res;
	return res;
}

bool get_new(void)
{
	if((int)lL.size()<=1 && fL.empty()) return 0;
	
	if(fL.empty())
	{
		int now = *lL.rbegin();
		lL.erase(now);
		lH.insert(now); ans += now;
	}
	else if((int)lL.size()<=1 || *fL.rbegin() > *lL.rbegin())
	{
		int now = *fL.rbegin();
		fL.erase(now);
		fH.insert(now); ans += now;
	}
	else
	{
		int now = *lL.rbegin();
		lL.erase(now);
		lH.insert(now); ans += now;
	}
	return 1;
}

void clear(void)
{
	int cnt = (int)lH.size() + (int)lL.size();
	while(cnt > (int)fH.size() + (int)lH.size())
		if(!get_new()) break;
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int type, d;
		scanf("%d%d",&type,&d);
		
		if(d>0)
		{
			ans += d;
			
			erase_both();
			
			if(type==0) fL.insert(d);
			else lL.insert(d);
			
			clear();
		}
		else
		{
			d = -d;
			ans -= d;
			if(type==0)
			{
				if(fH.find(d) != fH.end())
				{
					fH.erase(d);
					ans -= d;
					get_new();
				}
				else fL.erase(d);
			}
			else
			{
				if(lH.find(d) != lH.end())
				{
					lH.erase(d);
					ans -= d;
				}
				else
				{
					lL.erase(d);
					erase_both();
					clear();
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}