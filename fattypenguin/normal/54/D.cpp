#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

string name;
int n,fi;
int f[155][155];
int from[155][155];
int lo[155][255];
char mask[155],mask2[155];;
char ans[155];

bool gen()
{
    memset(ans,0,sizeof(ans));
    memset(mask2,0,sizeof(mask2));
    for (int i = 0;i < name.size();++i)
        if (name[i] >= 'a' + fi) return false;
    for (int i = 0;i < n-name.size()+1;++i)
        mask2[i] = mask[i];
    for (int i = 0;i < n-name.size()+1;++i)
        if (mask[i] == '1')
            for (int j = 0;j < name.size();++j)
                ans[i+j] = name[j];
    for (int i = 0;i < n-name.size()+1;++i)
        if (mask[i] == '1')
            for (int j = 0;j < name.size();++j)
                if (ans[i+j] != name[j])
                    return false;
    char mask1[155] = {0};
    for (int i = 0;i < n-name.size()+1;++i)
        if (mask[i] == '1')
            for (int j = 0;j < name.size();++j)
                mask1[i+j] = '1';
    for (int i = 0;i < n-name.size()+1;++i)
        if (mask[i] == '0')
        {
            bool ouc = true;
            for (int j = 0;j < name.size();++j)
                if (!(mask1[i+j] && ans[i+j] == name[j]))
                {
                    ouc = false;
                    break;
                }
            if (ouc) return false;
        }

    for (int i = 0;i <  n;++i)
        mask[i] = mask1[i];
    memset(f,0,sizeof(f));
    memset(lo,0,sizeof(lo));
    memset(from,0,sizeof(from));
    for (int i = 0;i <= name.size();++i)
        for (int j = 'a';j < 'a'+fi;++j)
        {
            string str1 = "";
            for (int k = 0;k < i;++k)
                str1 += name[k];
            str1 += j;
            for (int k = min(str1.size(),name.size());k >= 1;--k)
            {
                bool check = true;
                for (int r = 0;r < k;++r)
                    if (str1[str1.size()-k+r] != name[r])
                    {
                        check = false;
                        break;
                    }
                if (check)
                {
                    lo[i][j] = k;
                    break;
                }
            }
        }
    for (int i = 'a';i < 'a'+fi;++i)
        if (name[0] == i)
        {
            if (mask[0] != '1' && name.size() == 1) continue;
            f[0][1] = name[0];
        }
        else
            if (mask[0] != '1')
            {
                if (name[0] != 'a') f[0][0] = 'a';
                else if (fi > 1) f[0][0] = 'b';
            }
    for (int i = 1;i < n;++i)
        for (int j = 0;j <= name.size();++j)
        {
            if (f[i-1][j] > 0)
            {
                if (mask[i] == '1')
                {
                    if (lo[j][ans[i]] == name.size() && '1' != mask2[i-name.size()+1]) continue;
                    f[i][lo[j][ans[i]]] = ans[i];
                    from[i][lo[j][ans[i]]] = j;
                    continue;
                }
                for (int k = 'a';k <  'a'+fi;++k)
                {
                    if (lo[j][k] == name.size()) continue;
                    f[i][lo[j][k]] = k;
                    from[i][lo[j][k]] = j;
                }
            }
        }
    int where = -1;
    for (int i = 0;i <= name.size();++i)
        if (f[n-1][i] > 0)
        {
            where = i;
            break;
        }
    if (-1 == where) return false;
    for (int i = n-1;i >= 0;--i)
    {
        ans[i] = f[i][where];
        where = from[i][where];
    }
    return true;

}


int main()
{
    memset(mask,0,sizeof(mask));
    cin >> n >> fi;
    cin >> name;
    cin >> mask;
    if (gen())
    {
        for (int i = 0;i < n;++i)
            cout << ans[i];
        cout << endl;
    }
    else
        cout << "No solution\n";
    return 0;
}