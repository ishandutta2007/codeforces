using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            const Int64 mod = 1000000007;
            string[] t = Console.ReadLine().Split(
                new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(t[0]);
            int m = int.Parse(t[1]);
            int k = int.Parse(t[2]);
            if (n == k)
            {
                Int64 res = 1;
                for (int i = 0; i < n / 2 + n % 2; i++)
                    res = (res * m) % mod;
                Console.WriteLine(res);
                return;
            }
            if ((k > n) || (k == 1))
            {
                Int64 res = 1;
                for (int i = 0; i < n; i++)
                    res = (res * m) % mod;
                Console.WriteLine(res);
                return;
            }
            if (k % 2 == 0)
            {
                Console.WriteLine(m);
                return;
            }
            Console.WriteLine(m * m);
        }
    }
}