#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, len, a[100000], k;
bool u[100000];
long long sum, maxx = -1e18;

struct elem
{
    int val, id;
};

struct cmp1 : public std::binary_function<elem*, elem*, bool>
{
    bool operator()(elem& lhs, elem& rhs) const
    {
        return lhs.val < rhs.val;
    }
};

struct cmp2 : public std::binary_function<elem*, elem*, bool>
{
    bool operator()(elem& lhs, elem& rhs) const
    {
        return lhs.val > rhs.val;
    }
};

int main(void)
{
    cin >> n >> len;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> k;
    for (int t = 0; t < 2; ++t)
    {
        for (int i = 0; i < n; ++i)
            u[i] = false;
        int kk = k;
        sum = 0;
        priority_queue<elem, vector<elem>, cmp1> qmax;
        priority_queue<elem, vector<elem>, cmp2> qmin;
        for (int i = 0; i < n; ++i)
        {
            if (i >= len)
            {
                if (u[i - len])
                {
                    ++kk;
                    sum += a[i - len];
                    while (qmax.size())
                    {
                        elem e = qmax.top();
                        qmax.pop();
                        if (e.id > i - len)
                        {
                            sum += e.val * 2;
                            u[e.id] = true;
                            qmin.push(e);
                            --kk;
                            break;
                        }
                    }
                }
                else
                    sum -= a[i - len];
            }
            if (a[i] >= 0)
                sum += a[i];
            else
            {
                if (kk > 0)
                {
                    sum -= a[i];
                    --kk;
                    elem e;
                    e.id = i;
                    e.val = -a[i];
                    u[i] = true;
                    qmin.push(e);
                }
                else
                {
                    sum += a[i];
                    bool flag = true;
                    while (qmin.size())
                    {
                        elem e = qmin.top();
                        if (e.id > i - len)
                        {
                            if (e.val < -a[i])
                            {
                                qmin.pop();
                                elem e1;
                                e1.id = i;
                                e1.val = -a[i];
                                sum += (e1.val - e.val) * 2;
                                u[e.id] = false;
                                qmax.push(e);
                                u[e1.id] = true;
                                flag = false;
                                qmin.push(e1);
                            }
                            break;
                        }
                        else
                            qmin.pop();
                    }
                    if (flag)
                    {
                        elem e;
                        e.id = i;
                        e.val = -a[i];
                        qmax.push(e);
                    }
                }
            }
            if ((i >= len - 1) && (sum > maxx))
                maxx = sum;
        }
        for (int i = 0; i < n; ++i)
            a[i] *= -1;
    }
    cout << maxx << endl;
    return 0;
}