using System;
using System.Collections.Generic;

class Program
{
	static void Main()
	{
		string str;
		int n = Convert.ToInt32(Console.ReadLine());
		var times = new List<int>();
		for (var i = 0; i < n; ++i)
		{ 
			str = Console.ReadLine();
			int curtime = ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + (str[3] - '0') * 10 + (str[4] - '0');
			times.Add(curtime);
		}
		
		times.Sort();
		int ans = 0;
		for (var i = 0; i < times.Count - 1; ++i) {
			ans = Math.Max(ans, times[i + 1] - times[i]);
		}
		ans = Math.Max(ans, times[0] - times[times.Count - 1] + 24 * 60);

		ans = ans - 1;
		str = "" + (char)('0' + ans / 60 / 10);
		str = str + (char)('0' + ans / 60 % 10);
		str = str + ":";
		str = str + (char)('0' + ans % 60 / 10);
		str = str + (char)('0' + ans % 60 % 10);

		Console.WriteLine(str);
	}
}