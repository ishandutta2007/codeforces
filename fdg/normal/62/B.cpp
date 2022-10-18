#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <ctime>
#include <cmath>
#include <map>

#define ll unsigned long long

using namespace std;

char mas[200003]={0},mas1[200002]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k;
    vector <int> let[26];
    cin >> n >> k;
    scanf("%s\n",mas);
    for(int i=0;i<k;i++)
        let[mas[i]-'a'].push_back(i);
    for(int i=0;i<n;i++)
    {
        gets(mas1);
        int l=strlen(mas1);
        ll cur=0;
        for(int j=0;j<l;j++)
        {
            vector <int>::iterator it=lower_bound(let[mas1[j]-'a'].begin(),let[mas1[j]-'a'].end(),j);
            int res=l,r=let[mas1[j]-'a'].size()-1;
            if (let[mas1[j]-'a'].size()==0)
            {
                cur+=l;
                continue;
            }
            if (it!=let[mas1[j]-'a'].end()) r=it-let[mas1[j]-'a'].begin();
            if (r>=0&&r<l) res=labs(let[mas1[j]-'a'][r]-j);
            if (r-1>=0&&labs(let[mas1[j]-'a'][r-1]-j)<res) res=labs(let[mas1[j]-'a'][r-1]-j);
            cur+=res;
        }
        cout << cur << endl;
    }
    return 0;
}