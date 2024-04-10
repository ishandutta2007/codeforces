#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
//      ifstream cin("input.txt");
//      ofstream cout("output.txt");
        string s;
        cin >> s;
        int ans=0;
        for(int i=0;i<s.size();i++)
                for(int j=i+1;j<s.size();j++)
                {
                        if (s[i]==s[j])
                        {
                                int len=1;
                                while(j+len<s.size()&&s[i+len]==s[j+len]) len++;
                                if (len>ans) ans=len;
                        }
                }
        cout << ans << endl;
        return 0;
}