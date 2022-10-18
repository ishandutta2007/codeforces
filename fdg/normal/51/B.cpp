#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

string s;
char mas[5003]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    s="";
    while(cin >> mas) s+=mas;
    vector <int> ans,st;
    int level=-1,mx=-1,res=0;
    for(int i=0;i<s.size();i++)
    {
        if (s[i]=='<')
        {
            if (s[i+1]=='/')
            {
                if (s[i+2]=='t'&&s[i+3]=='a')
                {
                    if (res!=0) ans.push_back(res);
                    if (st.size()>0)
                    {
                        res=st.back();
                        st.pop_back();
                    }
                    else res=0;
                }
            }
            else
            {
                if (s[i+2]=='a')
                {
                    st.push_back(res);
                    res=0;
                }
                else
                    if (s[i+2]=='d') res++;
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans[0];
    for(int i=1;i<ans.size();i++)
        cout << " " << ans[i];
    cout << endl;
    return 0;
}