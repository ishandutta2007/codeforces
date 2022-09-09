import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Person implements Comparable<Person> {
		final int id, price, vote;
		boolean bought;

		public Person(int id, int price, int vote) {
			this.id = id;
			this.price = price;
			this.vote = vote;
		}
		
		public int compareTo(Person o) {
			if (price != o.price) {
				return o.price - price;
			}
			return id - o.id;
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		List<Person> people = new ArrayList<>();
		List<List<Person>> candidates = new ArrayList<>();
		candidates.add(new ArrayList<Person>());
		int forUs = 0;
		for (int i = 0; i < n; i++) {
			int vote = nextInt();
			int price = nextInt();
			if (vote == 0) {
				++forUs;
				continue;
			}
			--vote;
			people.add(new Person(i, price, vote));
			while (vote >= candidates.size()) {
				candidates.add(new ArrayList<Person>());
			}
			candidates.get(vote).add(people.get(people.size() - 1));
		}
		if (candidates.isEmpty()) {
			out.print(0);
			return;
		}
		Collections.sort(people);
		for (List<Person> l: candidates) {
			Collections.sort(l);
		}
		Collections.sort(candidates, new Comparator<List<Person>>() {
			public int compare(List<Person> o1, List<Person> o2) {
				return o2.size() - o1.size();
			}
		});
		long ans = Long.MAX_VALUE;
		List<Person> people2 = new ArrayList<>();
		long cans = 0;
		for (int maxEnemy = candidates.get(0).size(); maxEnemy >= 0; maxEnemy--) {
			for (List<Person> l: candidates) {
				if (l.size() <= maxEnemy) {
					break;
				}
				Person p = l.remove(l.size() - 1);
				p.bought = true;
				if (people2.isEmpty() || p.compareTo(people2.get(people2.size() - 1)) < 0) {
					++forUs;
					cans += p.price;
				}
			}
			if (maxEnemy == n) {
				continue;
			}
			while (forUs <= maxEnemy) {
				Person p = people.remove(people.size() - 1);
				if (p.bought) {
					continue;
				}
				++forUs;
				cans += p.price;
				people2.add(p);
			}
			while (!people2.isEmpty() && forUs > maxEnemy + 1) {
				Person p = people2.remove(people2.size() - 1);
				if (p.bought) {
					continue;
				}
				--forUs;
				cans -= p.price;
				people.add(p);
			}
			ans = min(ans, cans);
		}
		out.print(ans);
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}