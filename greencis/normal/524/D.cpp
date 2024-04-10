#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <stdlib.h> 
#include <iomanip>
//#pragma comment(linker, "/STACK:99999999999")
using namespace std;



struct blow
{
	int tim;
	int id;
	int num;
};

int toint(string s)
{
	int x1=(s[0]-'0')*10+(s[1]-'0');
	x1*=3600;
	int x2=(s[3]-'0')*10+(s[4]-'0');
	x2*=60;
	x1+=x2;
	x2=(s[6]-'0')*10+(s[7]-'0');
	return x2+x1;
}

bool cmp(blow a,blow b)
{
	if (a.tim==b.tim)
	{
		return a.id<b.id;
	}
	else
		return a.tim<b.tim;
}


int main()
{
	/*ifstream cin("input.txt");
    ofstream cout("output.txt");*/
	int n,m,t;
	cin>>n>>m>>t;
	//t--;
	int cur=1;
	int fl=0;
	int kol=0;
	vector <blow> w;
	for (int i=0;i<n;i++)
	{
		int y;
		string s;
		cin>>s;
		y=toint(s);
		blow job;
		job.tim=y;
		job.id=1;
		job.num=i;
		w.push_back(job);
		job.tim+=t;
		job.id=-1;
		w.push_back(job);
	}
	sort(w.begin(),w.end(),cmp);
	vector <pair <int,int> > ans;
	vector <int> dec(n+1,0);
	vector <int> inc(n+1,0);
	for (int i=0;i<w.size();i++)
	{
		if (w[i].id==-1)
		{
			if (dec[inc[w[i].num]]==w[i].num)
			{
				kol--;
			}
		}
		else
		{
			if (kol>=m)
			{
				ans.push_back(make_pair(w[i].num,cur-1));
				dec[cur-1]=w[i].num;
				inc[w[i].num]=cur-1;
			}
			else
			{
				ans.push_back(make_pair(w[i].num,cur));
				inc[w[i].num]=cur;
				dec[cur]=w[i].num;
				kol++;
				cur++;
				if (kol==m)
					fl=1;
			}
		}
	}
	if (fl==0)
	{
		cout<<"No solution"<<endl;
		return 0;
	}
	cout<<ans[n-1].second<<endl;
	sort(ans.begin(),ans.end());
	for (int i=0;i<n;i++)
	{
		cout<<ans[i].second<<"\n";
	}
	return 0;
}