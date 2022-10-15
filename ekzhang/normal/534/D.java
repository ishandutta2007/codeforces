import java.io.*;
import java.util.*;

public class D {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		Map<Integer, List<Integer>> greets = new HashMap<>();
		for (int i = 0; i < n; i++) {
			int currGreet = Integer.parseInt(st.nextToken());
			if (!greets.containsKey(currGreet)) {
				greets.put(currGreet, new ArrayList<Integer>());
			}
			greets.get(currGreet).add(i + 1);
		}
		int[] res = new int[n];
		int resIndex = 0;
		int people = 0;
		while (resIndex < n) {
			if (people < 3) {
				if (!greets.containsKey(people)) 
					break;
				List<Integer> names = greets.get(people);
				if (names.isEmpty()) 
					break;
				res[resIndex] = names.remove(names.size() - 1);
				resIndex++;
			}
			else {
				List<Integer> names = greets.containsKey(people) ? greets.get(people) :
						new ArrayList<Integer>();
				List<Integer> prevNames = greets.get(people - 3);
				if (!prevNames.isEmpty() && !(!names.isEmpty() 
						&& (greets.get(people - 2).isEmpty()
						|| greets.get(people - 1).isEmpty()))) {
					people -= 3;
					res[resIndex] = prevNames.remove(prevNames.size() - 1);
					resIndex++;
				}
				else {
					if (names.isEmpty()) {
						boolean found = false;
						for (int i = people - 3; i >= 0; i -= 3) {
							if (greets.get(i).size() > 0) {
								people = i;
								found = true;
								break;
							}
						}
						if (!found) break;
						else continue;
					}
					res[resIndex] = names.remove(names.size() - 1);
					resIndex++;
				}
			}
			people++;
		}
		if (resIndex == n) {
			out.println("Possible");
			for (int i = 0; i < n; i++) {
				out.print(res[i]);
				if (i != n - 1) {
					out.print(' ');
				}
			}
			out.println();
		}
		else {
			out.println("Impossible");
		}
		out.flush();
		System.exit(0);
	}

}