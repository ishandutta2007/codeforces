#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> ans;
bool finded;

void rec(int a[4],int kol = 0)
{
    if (ans.size()>=1001||finded||kol==3) return;
    if (a[0]%2==0&&a[1]%2==0)
    {
        a[0]/=2;
        a[1]/=2;
        ans.push_back("/1");
        if (a[0]==a[1]&&a[2]==a[3]&&a[0]==1&&a[2]==1)
        {
            finded=true;
            return;
        }
        rec(a);
        if (finded) return;
        a[0]*=2; a[1]*=2;
        ans.pop_back();
    }
    if (a[2]%2==0&&a[1]%2==0)
    {
        a[2]/=2;
        a[1]/=2;
        ans.push_back("/2");
        if (a[0]==a[1]&&a[2]==a[3]&&a[0]==1&&a[2]==1)
        {
            finded=true;
            return;
        }
        rec(a);
        if (finded) return;
        a[1]*=2; a[2]*=2;
        ans.pop_back();
    }
    if (a[2]%2==0&&a[3]%2==0)
    {
        a[2]/=2;
        a[3]/=2;
        ans.push_back("/3");
        if (a[0]==a[1]&&a[2]==a[3]&&a[0]==1&&a[2]==1)
        {
            finded=true;
            return;
        }
        rec(a);
        if (finded) return;
        a[2]*=2; a[3]*=2;
        ans.pop_back();
    }
    if (a[0]%2==0&&a[3]%2==0)
    {
        a[0]/=2;
        a[3]/=2;
        ans.push_back("/4");
        if (a[0]==a[1]&&a[2]==a[3]&&a[0]==1&&a[2]==1)
        {
            finded=true;
            return;
        }
        rec(a);
        if (finded) return;
        a[0]*=2; a[3]*=2;
        ans.pop_back();
    }
    if (a[0]!=1||a[1]!=1)
    {
        a[0]++;
        a[1]++;
        ans.push_back("+1");
        rec(a,kol+1);
        if (finded) return;
        a[0]--; a[1]--;
        ans.pop_back();
    }
    if (a[2]!=1||a[1]!=1)
    {
        a[2]++;
        a[1]++;
        ans.push_back("+2");
        rec(a,kol+1);
        if (finded) return;
        a[1]--; a[2]--;
        ans.pop_back();
    }
    if (a[2]!=1||a[3]!=1)
    {
        a[2]++;
        a[3]++;
        ans.push_back("+3");
        rec(a,kol+1);
        if (finded) return;
        a[2]--; a[3]--;
        ans.pop_back();
    }
    if (a[0]!=1||a[3]!=1)
    {
        a[0]++;
        a[3]++;
        ans.push_back("+4");
        rec(a,kol+1);
        if (finded) return;
        a[0]--; a[3]--;
        ans.pop_back();
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a[4]={0},n=4;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int last=-1;
    ans.clear();
    finded=false;
    rec(a);
    if (finded&&ans.size()<=1000)
    {
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << endl;
    }
    return 0;
}